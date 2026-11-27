# formatusb
gui wrapper around live-usb-maker (antix) for formating usb devices

[![latest packaged version(s)](https://repology.org/badge/latest-versions/formatusb.svg)](https://repology.org/project/formatusb/versions)

![image](https://github.com/MX-Linux/formatusb/assets/418436/1fe7aa5e-b762-493e-9a88-6d19fc8e1a91)

## AppImage

Download the x86-64 AppImage from the **Assets** section of a GitHub release,
make it executable, and run it as your desktop user. The AppImage includes Qt,
translations, offline help, the formatter, and MX device detection scripts.
Formatting uses the host's polkit authentication agent and `pkexec`. On Debian,
the disk tools are provided by `util-linux`, `fdisk`, `parted`, `udev`, and the
filesystem packages `dosfstools`, `e2fsprogs`, `exfatprogs`, and `ntfs-3g`.
If FUSE is unavailable, launch the image with `--appimage-extract-and-run`.

To build locally on x86-64 Debian 12:

```sh
sudo apt install build-essential cmake ninja-build dpkg-dev curl file qt6-base-dev \
    qt6-tools-dev qt6-tools-dev-tools libqt6svg6 qt6-translations-l10n qt6-wayland
./make-appimage.sh
```

The builder verifies and caches its packaging tools and writes
`build-appimage/formatusb-<version>-x86_64.AppImage` using the version in
`debian/changelog`. GitHub Actions attaches the AppImage to each non-Arch release.
