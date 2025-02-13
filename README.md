# FdF - 3D Wireframe Landscape Renderer

![FdF Preview](image.png)  

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

## 🎥 Demo

![FdF in Action](190404352-288d7bf1-5f43-4e2d-8033-f16bca534ca6.gif)  

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
