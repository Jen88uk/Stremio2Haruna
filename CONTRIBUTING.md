# Contributing to Stremio2Haruna

Thank you for your interest in contributing to Stremio2Haruna! This document provides guidelines for contributing to the project.

## How to Contribute

### Reporting Bugs

If you find a bug, please open an issue on GitHub with:
- A clear, descriptive title
- Steps to reproduce the issue
- Expected behavior vs actual behavior
- Your environment (OS, KDE Plasma version, Qt6 version)
- Relevant logs or error messages

### Suggesting Features

Feature suggestions are welcome! Please open an issue with:
- A clear description of the feature
- Why this feature would be useful
- How you envision it working
- Any potential implementation ideas (optional)

### Pull Requests

1. **Fork the repository** and create your branch from `main`
2. **Follow the code style** (see below)
3. **Test your changes** thoroughly
4. **Update documentation** if needed (README.md, etc.)
5. **Commit with clear messages** describing what and why
6. **Submit a pull request** with a clear description

## Development Setup

### Prerequisites

```bash
# Install dependencies (CachyOS/Arch)
sudo pacman -S cmake qt6-base wl-clipboard haruna
yay -S kdotool-git
```

### Building

```bash
mkdir build && cd build
cmake ..
make
```

### Testing

```bash
# Run the built executable
./build/stremio2haruna

# Test features:
# - Left-click tray icon for config dialog
# - Right-click for menu
# - Copy a URL in Stremio to test functionality
```

## Code Style

- **Language**: C++17
- **Formatting**: Follow existing code style
  - 2-space indentation
  - Qt naming conventions (camelCase for methods, m_ prefix for members)
  - Clear, descriptive variable names
- **Comments**: Use comments for non-obvious logic
- **Qt Best Practices**: Use Qt idioms and patterns

## Commit Messages

- Use clear, descriptive commit messages
- Start with a verb in present tense (Add, Fix, Update, etc.)
- Reference issue numbers when applicable (#123)

Example:
```
Add configurable polling interval

- Add QSettings integration for persistence
- Update UI with spin box control
- Fixes #45
```

## Code Review Process

1. Maintainer will review your PR
2. Address any feedback or requested changes
3. Once approved, your PR will be merged
4. Thank you for your contribution! 🎉

## Project Structure

```
Stremio2Haruna/
├── main.cpp              # Application entry point
├── stremio2haruna.h/cpp  # Main application logic
├── configdialog.h/cpp    # Configuration dialog
├── CMakeLists.txt        # Build configuration
├── resources.qrc         # Qt resources
└── README.md             # Documentation
```

## Areas for Contribution

Potential areas where contributions would be valuable:

- **Testing**: Test on different Linux distributions/DEs
- **Features**: New configuration options or improvements
- **Bug Fixes**: Address open issues
- **Documentation**: Improve guides, comments, or examples
- **Translations**: While not currently supported, this could be a future area

## Questions?

If you have questions about contributing, feel free to:
- Open a discussion on GitHub
- Ask in an issue
- Reach out to the maintainer

## License

By contributing to Stremio2Haruna, you agree that your contributions will be licensed under the GNU General Public License v3.0, the same license as the project.

## Code of Conduct

This project adheres to the Contributor Covenant [Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code.

---

Thank you for helping make Stremio2Haruna better! 🚀
