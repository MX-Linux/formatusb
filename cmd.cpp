/**********************************************************************
 *  cmd.cpp
 **********************************************************************
 * Copyright (C) 2019-2026 MX Authors
 *
 * Authors: Dolphin Oracle
 *          MX Linux <http://mxlinux.org>
 *          using live-usb-maker by BitJam
 *          and mx-live-usb-maker gui by adrian
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package. If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#include "cmd.h"

#include <QDebug>
#include <QEventLoop>

Cmd::Cmd(QObject *parent)
    : QProcess(parent)
{
    connect(this, &Cmd::readyReadStandardOutput, [this]() { emit outputAvailable(readAllStandardOutput()); });
    connect(this, &Cmd::readyReadStandardError, [this]() { emit errorAvailable(readAllStandardError()); });
    connect(this, &Cmd::outputAvailable, [this](const QString &out) { outBuffer += out; });
    connect(this, &Cmd::errorAvailable, [this](const QString &out) { outBuffer += out; });
}

bool Cmd::run(const QString &cmd, bool quiet)
{
    outBuffer.clear();
    QString output;
    return run(cmd, output, quiet);
}

// util function for getting bash command output
QString Cmd::getCmdOut(const QString &cmd, bool quiet)
{
    outBuffer.clear();
    QString output;
    run(cmd, output, quiet);
    return output;
}

bool Cmd::run(const QString &cmd, QString &output, bool quiet)
{
    return runProgram(QStringLiteral("/bin/bash"), {QStringLiteral("-c"), cmd}, output, quiet);
}

bool Cmd::runProgram(const QString &program, const QStringList &args, QString &output, bool quiet)
{
    outBuffer.clear();
    connect(this, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &Cmd::finished, Qt::UniqueConnection);
    if (this->state() != QProcess::NotRunning) {
        qDebug() << "Process already running:" << this->program() << this->arguments();
        return false;
    }
    if (!quiet) qDebug() << program << args;
    QEventLoop loop;
    connect(this, &Cmd::finished, &loop, &QEventLoop::quit, Qt::UniqueConnection);
    connect(this, &QProcess::errorOccurred, &loop, [&loop](QProcess::ProcessError error) {
        if (error == QProcess::FailedToStart) {
            loop.quit();
        }
    });
    start(program, args);
    if (error() != QProcess::FailedToStart) {
        loop.exec();
    }
    output = outBuffer.trimmed();
    return error() != QProcess::FailedToStart && exitStatus() == QProcess::NormalExit && exitCode() == 0;
}
