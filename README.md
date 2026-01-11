# Stremio2Haruna

A Qt6-based system tray application for KDE Plasma (Wayland) that automatically detects when you copy URLs in Stremio and launches them in Haruna media player.

## Features

- 🎯 Monitors clipboard for URLs when Stremio is running
- ⏱️ Waits 2.5 seconds before launching Haruna (gives you time to close/pause Stremio)
- 🎬 Automatically pauses monitoring while Haruna is playing (no fullscreen interference)
- 🔄 Auto-resumes monitoring when you close Haruna
- 🔘 Easy enable/disable toggle via system tray menu
- 🚀 Launches Haruna media player with the copied URL
- 💻 Native Qt6 application optimized for KDE Plasma on Wayland

## System Requirements

- **OS**: Linux with Wayland (tested on CachyOS)
- **Desktop Environment**: KDE Plasma
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard (for Wayland clipboard access)
  - kdotool (for window detection on Wayland)
  - CMake (for building)
  - Stremio (the application to monitor)
  - Haruna (media player to launch)

## Prerequisites

### 1. Install kdotool (for window detection)

`kdotool` is required for detecting the active window on KDE Plasma Wayland.

Install from AUR:
```bash
yay -S kdotool-git
```

Or manually from GitHub: https://github.com/jinliu/kdotool

### 2. Install wl-clipboard (for clipboard access)

`wl-clipboard` is required for Qt to access the Wayland clipboard.

```bash
sudo pacman -S wl-clipboard
```

## Building

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
make

# Optionally install
sudo make install
```

## Usage

1. Start the application:
   ```bash
   ./stremio2haruna
   ```

2. The application will run in the background with a system tray icon

3. Right-click the tray icon to:
   - Toggle enabled/disabled state
   - Quit the application

4. When enabled and Stremio is running:
   - Copy any URL to your clipboard (e.g., from Stremio's video player menu)
   - The app will wait 2.5 seconds, then launch Haruna with the URL

## How It Works

1. **Clipboard Monitoring**: Uses `wl-paste` polling (every 3.5 seconds) to detect clipboard changes on Wayland
2. **Stremio Detection**: Uses `kdotool` to check if Stremio is running
3. **URL Validation**: Checks if the clipboard content is a valid URL with supported schemes  
4. **Delay**: Waits 2.5 seconds to give you time to close/pause Stremio
5. **Haruna Launch**: Launches Haruna media player with the URL and monitors the process
6. **Auto Pause/Resume**: Stops clipboard polling while Haruna is running (prevents fullscreen glitches), automatically resumes when you close Haruna

## Known Limitations

- **KDE-specific**: Uses `kdotool` which requires KDE Plasma/KWin
- **Wayland-only**: Designed for Wayland; X11 may work but is untested
- **Polling interval**: Uses 3.5-second polling to avoid menu interference

## Troubleshooting

### Clipboard not detected
- Ensure `wl-clipboard` is installed: `which wl-paste`
- The polling interval is 2 seconds, so there may be a slight delay

### Stremio detection not working
- Ensure `kdotool` is installed: `which kdotool`
- Test manually: `kdotool search --class com.stremio.stremio`

### Haruna doesn't launch
- Verify Haruna is installed: `which haruna`
- Test manually: `haruna <some-url>`

## License

This project is open source. Feel free to modify and distribute as needed.

## Contributing

Contributions, bug reports, and feature requests are welcome!
