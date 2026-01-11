# Dependencies

## Build-Time Dependencies

### Required
- **CMake** >= 3.16
  - Build system generator
  
- **Qt6** >= 6.0
  - Qt6::Core - Core Qt functionality
  - Qt6::Widgets - Widget toolkit for GUI
  - Qt6::Gui - GUI module
  - Qt6::DBus - D-Bus IPC support
  
- **C++ Compiler** with C++17 support
  - GCC >= 7.0 or
  - Clang >= 5.0

## Runtime Dependencies

### Required System Utilities
- **wl-clipboard**
  - Provides `wl-paste` for Wayland clipboard access
  - Install: `sudo pacman -S wl-clipboard` (Arch/CachyOS)
  
- **kdotool**
  - Window detection on KDE Plasma/Wayland
  - Install: `yay -S kdotool-git` (AUR)
  - Source: https://github.com/jinliu/kdotool

### Required Applications
- **Stremio**
  - Source application for URL copying
  - The application this tool monitors
  
- **Haruna**
  - Target media player
  - URLs are automatically launched in Haruna
  - Install: `sudo pacman -S haruna`

## Platform Requirements

- **Operating System**: Linux with Wayland support
- **Desktop Environment**: KDE Plasma
- **Wayland Compositor**: KWin (KDE's compositor)

## Optional Dependencies

None at this time.

## Dependency Graph

```
Stremio2Haruna
├── Build Dependencies
│   ├── CMake (>= 3.16)
│   ├── C++17 Compiler
│   └── Qt6
│       ├── Qt6::Core
│       ├── Qt6::Widgets
│       ├── Qt6::Gui
│       └── Qt6::DBus
│
└── Runtime Dependencies
    ├── System Utilities
    │   ├── wl-clipboard (wl-paste)
    │   └── kdotool
    │
    └── Applications
        ├── Stremio (monitored app)
        └── Haruna (target player)
```

## Version Compatibility

- **Qt6**: Tested with Qt 6.x on CachyOS
- **KDE Plasma**: Tested on KDE Plasma 6 (Wayland)
- **wl-clipboard**: Any recent version
- **kdotool**: Latest from AUR (kdotool-git)

## Installation Notes

All dependencies must be installed before building and running Stremio2Haruna. See the main [README.md](README.md) for detailed installation instructions.
