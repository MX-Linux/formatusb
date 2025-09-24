# formatusb
gui wrapper around live-usb-maker (antix) for formating usb devices

[![latest packaged version(s)](https://repology.org/badge/latest-versions/formatusb.svg)](https://repology.org/project/formatusb/versions)

![image](https://github.com/MX-Linux/formatusb/assets/418436/1fe7aa5e-b762-493e-9a88-6d19fc8e1a91)


# 📦 FormatUSB

FormatUSB is a simple graphical tool for formatting USB drives on Linux. It provides an easy-to-use interface for selecting, erasing, and formatting removable storage devices without needing to type complex terminal commands.

## ✨ Features

- Detects removable USB devices automatically
- Supports common filesystems: **FAT32, NTFS, ext4, exFAT**
- Simple GUI built with **Qt**
- Allows quick erase and reformatting

## 🖥️ Requirements

Before building FormatUSB, make sure the following packages are installed:

```bash
sudo apt update
sudo apt install -y build-essential qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```

### Optional (for Git clone)

```bash
sudo apt install -y git
```

## 🔧 Building From Source

1. **Clone the repository**
   ```bash
   git clone https://github.com/WHO-AM-I-404/formatusb.git
   cd formatusb
   ```

2. **Generate Makefile**
   ```bash
   qmake
   ```

3. **Compile the project**
   ```bash
   make
   ```

4. After compilation, the executable `formatusb` will be created in the project directory.

## 🚀 Running FormatUSB

Run the binary with:

```bash
./formatusb
```

Or, install it globally so it can be run from anywhere:

```bash
sudo cp formatusb /usr/local/bin/
```

Now you can simply run:

```bash
formatusb
```

## 📂 Installing System-Wide

For easier access, you can also copy the `.desktop` entry:

1. **Copy binary:**
   ```bash
   sudo cp formatusb /usr/local/bin/
   ```

2. **Create a desktop entry:**
   ```bash
   sudo nano /usr/share/applications/formatusb.desktop
   ```

   Paste this content:
   ```ini
   [Desktop Entry]
   Name=FormatUSB
   Exec=formatusb
   Icon=drive-removable-media-usb
   Type=Application
   Categories=Utility;System;
   ```

3. **Save and update desktop database:**
   ```bash
   sudo update-desktop-database
   ```

Now FormatUSB will appear in your system menu/launcher.

## 🛠️ Usage

1. Plug in your USB drive
2. Open **FormatUSB**
3. Select your USB device from the list
4. Choose the filesystem format (FAT32/NTFS/ext4/exFAT)
5. Click **Format**
6. Wait until the process completes

⚠️ **Warning:** Formatting will erase all data on the USB drive.

## 📦 Packaging (Optional)

If you want to distribute FormatUSB without requiring dependencies, you can build an **AppImage**:

1. **Install AppImage tools:**
   ```bash
   sudo apt install -y appimagetool
   ```

2. **Package the compiled binary into an AppDir and run:**
   ```bash
   appimagetool AppDir
   ```

This will generate a portable `.AppImage` file that can run on most Linux systems.

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Open a Pull Request

## 📜 License

This project follows the license of the original repository. Please check the LICENSE file for details.
