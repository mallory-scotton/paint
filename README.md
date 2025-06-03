# 🎨 MyPaint - Advanced Digital Painting Application

A professional-grade digital painting application built with C and CSFML, featuring a comprehensive toolkit for digital artists and designers. MyPaint provides an intuitive interface with powerful drawing tools, layer management, and extensive canvas manipulation capabilities.

## 📋 Project Overview

MyPaint is a feature-rich digital painting application designed for artists, designers, and creative professionals. Built using C programming language and the CSFML (Simple and Fast Multimedia Library), it offers a modern, user-friendly interface with professional-grade tools for digital art creation.

The application follows a modular architecture with separate components for canvas management, tool handling, widget rendering, and event processing, ensuring maintainable and extensible code.

## ✨ Features

### 🖌️ Drawing Tools
- **Pencil Tool**: Precise line drawing with customizable thickness
- **Brush Tool**: Smooth brush strokes with pressure-sensitive opacity
- **Eraser Tool**: Clean erasure with adjustable size
- **Bucket Fill**: Flood fill tool for quick area coloring
- **Color Picker**: Sample colors directly from the canvas

### 🎨 Canvas Management
- **Multi-canvas Support**: Work with multiple canvases simultaneously
- **Zoom & Pan**: Smooth zooming (1/128x to 64x) and canvas navigation
- **Canvas Transformation**: Scale, rotate, and position canvases
- **Transparent Background**: Professional transparency grid display
- **Custom Canvas Sizes**: Support for various preset and custom dimensions

### 🎛️ User Interface
- **Modern Dark Theme**: Professional dark interface design
- **Customizable Toolbar**: Comprehensive tool selection panel
- **Color Picker Widget**: Advanced color selection with RGB/HSV support
- **Layers Panel**: Professional layer management interface
- **Property Panels**: Tool-specific options and settings

### 💾 File Operations
- **Multiple Formats**: Support for PNG, JPG, BMP, TGA image formats
- **Import/Export**: Open existing images and save your artwork
- **Save As Options**: Choose from multiple export formats

### ⌨️ Keyboard Shortcuts
- `Alt + Scroll`: Zoom in/out
- `Ctrl + Scroll`: Horizontal canvas movement
- `+/-`: Adjust tool thickness
- Various menu shortcuts for quick access

## 🖼️ Gallery

![Demo Animation](screenshots/demo.gif)

<div align="center">
  <img src="screenshots/new-project.png" alt="New Project Creation" width="45%">
  <img src="screenshots/blank-canvas.png" alt="Blank Canvas" width="45%">
</div>

<div align="center">
  <img src="screenshots/color.png" alt="Color Picker" width="45%">
  <img src="screenshots/save-as.png" alt="Save Options" width="45%">
</div>

## 🚀 Installation

### Prerequisites

Before building MyPaint, ensure you have the following dependencies installed:

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential gcc libcsfml-dev libsfml-dev
```

**Fedora/CentOS:**
```bash
sudo dnf install gcc make CSFML-devel SFML-devel
```

**Arch Linux:**
```bash
sudo pacman -S gcc make csfml sfml
```

### Building from Source

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/paint.git
   cd paint
   ```

2. **Build the application:**
   ```bash
   make
   ```

3. **Run MyPaint:**
   ```bash
   ./my_paint
   ```

## 🎯 Usage

### Getting Started

1. **Launch the application:**
   ```bash
   ./my_paint
   ```

2. **Create a new canvas:**
   - Use the File menu to create a new project
   - Choose from preset canvas sizes or create custom dimensions
   - Select your preferred background color

3. **Select drawing tools:**
   - Click on tools in the left toolbar
   - Adjust thickness and opacity in the tool options panel
   - Use the color picker to choose your colors

4. **Save your work:**
   - Use File > Save As to export in various formats
   - Choose from PNG, JPG, BMP, or TGA formats

### Advanced Features

- **Canvas Navigation**: Use Alt+Scroll for zooming, Ctrl+Scroll for panning
- **Tool Customization**: Adjust brush thickness and opacity in real-time
- **Color Management**: Use the advanced color picker with RGB/HSV controls
- **Layer Support**: Manage multiple layers for complex compositions

## 🔧 Build Instructions

### Development Build

For development with debugging symbols:
```bash
make
```

### Clean Build

To clean and rebuild:
```bash
make clean
make
```

### Testing

Run the test suite:
```bash
make tests_run
```

### Code Style

Check coding style compliance:
```bash
make style
```

## 📦 Dependencies

### Core Libraries
- **CSFML**: Simple and Fast Multimedia Library for C
  - `libcsfml-system`
  - `libcsfml-window`
  - `libcsfml-graphics`
  - `libcsfml-network`
  - `libcsfml-audio`

### System Dependencies
- **GCC**: GNU Compiler Collection
- **Make**: Build automation tool
- **Math Library**: `libm` for mathematical operations

### Development Dependencies
- **Criterion**: Unit testing framework (for testing)
- **gcovr**: Code coverage reporting (for testing)

### Asset Requirements
- OpenSans font (`assets/opensans.ttf`)
- Tool icons and UI assets (PNG format)
- Transparency grid texture

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

```
MIT License

Copyright (c) 2024 TekyoDrift

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

## 🤝 Contributing

We welcome contributions to MyPaint! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting pull requests.

### How to Contribute

1. **Fork the repository**
2. **Create a feature branch** (`git checkout -b feature/amazing-feature`)
3. **Commit your changes** (`git commit -m 'Add amazing feature'`)
4. **Push to the branch** (`git push origin feature/amazing-feature`)
5. **Open a Pull Request**

### Development Guidelines

- Follow the existing code style and conventions
- Add appropriate documentation for new features
- Include tests for new functionality
- Update the README.md if needed

### Code of Conduct

Please note that this project is released with a Contributor Code of Conduct. By participating in this project you agree to abide by its terms.

## 📧 Contact

**Project Maintainer:** Mallory Scotton  
**Email:** [mscotton.pro@gmail.com](mailto:mscotton.pro@gmail.com)

**Project Contributors:**
- Mallory Scotton - [mallory.scotton@epitech.eu](mailto:mallory.scotton@epitech.eu)
- Hugo Cathelain - [hugo.cathelain@epitech.eu](mailto:hugo.cathelain@epitech.eu)

**Project Information:**
- **Institution:** Epitech
- **Year:** 2024
- **Course:** B-MUL-200 (Multimedia Programming)

---

*Crafted with ❤️ and countless hours of coding* ✨

Made with passion for digital art and the C programming language. MyPaint represents the culmination of advanced graphics programming, user interface design, and software architecture principles.
