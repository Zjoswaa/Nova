# Changelog
All notable changes for Nova will be documented in this file.

## 0.0.1 (31/10/2024)
**Initial Commit**
- **Features**:
  - Started Nova-Engine project using CMake as the build system.
    - Added Nova project, this will be the engine library.
    - Added Sandbox project, to test library functionality.
  - Added Git submodules and dependencies, see `README.md` for the full list.
  - Now shows a window with the ImGui demo window inside.

## 0.0.2 (1/11/2024)
- **Features**
  - Added logging functionality with the `Log` class.
  - Added log macros, all of them are added to the Sandbox project
  - Created an ImGui window that shows OpenGL information:
    - OpenGL Version
    - Vendor
    - Renderer
    - GLSL Version
  - The OpenGL information window can be closed by right-clicking on it and pressing "Close" on the popup menu.
