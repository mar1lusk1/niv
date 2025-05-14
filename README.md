<div align="center">
    <h1>Niv</h1>
    <p><i>Lightweight, fast and simple game engine for C and Lua</i></p>
    <img alt="GitHub License" src="https://img.shields.io/github/license/mar1lusk1/niv">
    <img alt="Github Stars" src="https://img.shields.io/github/stars/mar1lusk1/niv?style=flat">
    <img alt="Github Forks" src="https://img.shields.io/github/forks/mar1lusk1/niv?style=flat">
    <img alt="GitHub Actions Workflow Status" src="https://img.shields.io/github/actions/workflow/status/mar1lusk1/niv/Makefile">
</div>

---

<p align="center">
    <a href="#about">About</a>
    <a href="#features">Features</a>
    <a href="#installation">Installation</a>
    <a href="#usage">Usage</a>
    <a href="#documentation">Documentation</a>
    <a href="#license">License</a>
</p>

---

## About ##

Niv is a **free & open-source**, **lightweight**, **fast** and **simple** game engine for C and Lua.

## Features ##

- **🪶 Lightweight**: Niv requires a *few* megabytes of memory to run
- **🚀 Fast**: Niv is extremely fast
- **🖥️ Portable**: Niv can run on (*almost*) every device you can think of.
- **🎮 Simple**: Niv can be learnt on *minutes*.

## Installation ##

<details>
<summary>Linux, macOS and FreeBSD</summary>

Open up the terminal and run:

> [!NOTE]
> Make sure you have [`git`](https://git-scm.com/) installed.

```bash
git clone https://github.com/mar1lusk1/niv.git
cd niv
make all
make install
```

</details>

<details>
<summary>Windows</summary>

Open up the terminal and run:

> [!NOTE]
> As before, make sure you have [`git`](https://git-scm.com/) installed.

```powershell
git clone https://github.com/mar1lusk1/niv.git
cd niv
./build.ps1
```

## Usage ##

First, to make a new project, run:

```bash
niv new <project_name>
```

It will generate this folder structure:

```plaintext
<project_name>
├── CMakeLists.txt
├── src
│   └── setup.c
|   └── shaders
|   |   └── high-res.xml
|   |   └── low-res.xml
|   └── main.c
|   └── behaviour-player.lua
|   NivProject.nv
└── README.md
```

To run the project, run:

```bash
niv run <project_name>
```

Or to make an executable just use [`cmake`](https://cmake.org/):

```bash
cmake --build <project_name>
```

> [!IMPORTANT]
> It will generate the executable at `<project_name>/build/<project_name>.[exe|out]`

## Documentation ##

- [Wiki](https://github.com/mar1lusk1/niv/wiki)
- [Reference](https://github.com/mar1lusk1/niv/wiki/Reference)
