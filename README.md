# FdF - 3D Wireframe Landscape Renderer

![FdF Preview](https://private-user-images.githubusercontent.com/144660747/412892986-837dc704-c347-428f-a83a-6cfc85db032b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mzk0NTE0MTAsIm5iZiI6MTczOTQ1MTExMCwicGF0aCI6Ii8xNDQ2NjA3NDcvNDEyODkyOTg2LTgzN2RjNzA0LWMzNDctNDI4Zi1hODNhLTZjZmM4NWRiMDMyYi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMjEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDIxM1QxMjUxNTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wZDJiNDk5ZWRmYjBmNjBkYmFlOTZhMDU0MjdlNDc5MGEzNTA0ZmE4ZTYyMzA5ODBjN2Y1YWEwOWZmYzQxYjhhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.lsYHG9i62zFat_14735Uza5M6-NtgeXvwMevTBAzrGY)  

## 🔥 Introduction

**FdF (Fil de Fer)** is a stunning **3D wireframe landscape renderer** that brings terrains to life using line-based rendering. It processes height maps from files and transforms them into **interactive** and **dynamic** visualizations. This project is developed in **C**, utilizing the **MiniLibX** graphics library for real-time rendering and interaction.

This version includes **all bonuses**, making it one of the most feature-complete implementations of FdF. The final bonus allows users to dynamically **change altitude**, adding an extra layer of customization.

## 🎮 Features

✔️ **3D Wireframe Rendering** – Displays landscapes in an isometric view with perspective.  
✔️ **Dynamic Projection Changes** – Switch between **isometric**, **parallel**, and **other perspectives** with a key press.  
✔️ **Full Camera Control** –  
&nbsp; &nbsp; ◾ **Pan (Move the View)**  
&nbsp; &nbsp; ◾ **Rotate (X/Y axes)**  
&nbsp; &nbsp; ◾ **Zoom In/Out**  
✔️ **Altitude Modification (Bonus)** – Adjust terrain heights dynamically.  
✔️ **Grid Display Toggle** – Show or hide the base grid for clarity.  
✔️ **High Performance Rendering** – Optimized line-drawing algorithm for smooth visuals.  

## 🖥️ How It Works

1. **Load a height map** – The program reads `.fdf` files, which contain height data.
2. **Render the wireframe** – Transforms 2D coordinate data into a 3D projection.
3. **Interact in real-time** – Move, rotate, zoom, and even modify terrain altitude dynamically.

## Demo

![Demo GIF](https://private-user-images.githubusercontent.com/144660747/412891778-e35d4b03-d6bc-4e57-a37b-99df9ad7cc85.gif?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mzk0NTEyODQsIm5iZiI6MTczOTQ1MDk4NCwicGF0aCI6Ii8xNDQ2NjA3NDcvNDEyODkxNzc4LWUzNWQ0YjAzLWQ2YmMtNGU1Ny1hMzdiLTk5ZGY5YWQ3Y2M4NS5naWY_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMjEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDIxM1QxMjQ5NDRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kOWUwZTg3M2Y5ODAyZjVjYjlmOTlkYjc0ZDY1NzE0YTZlZjRiMjNiNzQ3ZWU1ZDcwMGIyNDA0MmQyYzlhNGZmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.OEOqz44DAj7X8bZ8hb-L1Jfy6V2fVaeJC0tcqxlZ8BU)

## 🛠️ Installation & Usage

### 📥 Prerequisites

- **Linux/macOS**
- `gcc` (or another C compiler)
- `make`
- `MiniLibX` (graphics library)

### 🚀 Build & Run

1. Clone the repository:  
   ```bash
   git clone https://github.com/your-username/FdF.git
   cd FdF
   ```
2. Compile the program:  
   ```bash
   make
   ```
3. Run it with a sample height map:  
   ```bash
   ./fdf 42.fdf
   ```

### 🎮 Controls

| Action            | Key / Mouse    |
|------------------|---------------|
| **Pan (Move view)** | Left-click + Drag |
| **Rotate (X/Y axes)** | Right-click + Drag |
| **Zoom In/Out** | Scroll Wheel |
| **Change Projection** | `P` |
| **Modify Altitude** | `+ / -` |
| **Flatten Terrain** | `/` |

## 💡 Credits

Developed by **Anastasiia Pashkova**  
Built as part of the **42 Core Curriculum**  
