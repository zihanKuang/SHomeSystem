
# SHomeSystem

A smart home automation system built with C/C++ (for the backend server) and Qt (for the client interface). The server uses **SQLite** as its database, and the client relies on **Qt** widgets, charts, and networking modules.  

## Table of Contents
1. [Overview](#overview)  
2. [Features](#features)  
3. [Project Structure](#project-structure)  
4. [Prerequisites](#prerequisites)  
5. [Building the Server on Linux](#building-the-server-on-linux)  
6. [Running the Server](#running-the-server)  
7. [Building the Client with Qt Creator](#building-the-client-with-qt-creator)  
8. [Running the Client](#running-the-client)  
9. [Key Source Files Explanation](#key-source-files-explanation)  
   - [Server Side](#server-side)  
   - [Client Side](#client-side)  
10. [Troubleshooting](#troubleshooting)  
---

## 1. Overview
**SHomeSystem** allows you to control and monitor home devices (air conditioners, lights, humidifiers, etc.) through a client application built with Qt. A C-based server handles the logic of registering users, logging them in, and receiving device status updates or analysis requests. The server uses SQLite for data storage and [microhttpd](https://www.gnu.org/software/libmicrohttpd/) along with libcurl for HTTP APIs.

---

## 2. Features

- **User Authentication**: Registration and login using SQLite as a credentials store.  
- **Device Control**: Toggle states (on/off) and set timers for air conditioners, lights, humidifiers, etc.  
- **Data Analysis**: Retrieve daily power consumption data for each device via the server.  
- **Charts & Visualization**: Qt Charts (line charts, bar charts) for monitoring power usage and environmental data (temperature, humidity).  
- **Weather Updates**: Fetch external weather data for demonstration (e.g., from a third-party API).  

---

## 3. Project Structure

A simplified view of important files and folders:

```
SHomeSystem/
│
├── client/
│   ├── src/
│   │   ├── SHomeSystem.pro             # Qt project file
│   │   ├── main.cpp
│   │   ├── widget.cpp/.h/.ui
│   │   ├── tabwidget.cpp/.h/.ui
│   │   ├── loginview.cpp/.h/.ui
│   │   ├── registerview.cpp/.h/.ui
│   │   ├── datawidget.cpp/.h/.ui
│   │   ├── environmentwidget.cpp/.h/.ui
│   │   ├── weatherwidget.cpp/.h/.ui
│   │   ├── device.cpp/.h
│   │   ├── executor.cpp/.h
│   │   ├── sensormodule.cpp/.h
│   │   ├── communicationinterface.cpp/.h
│   │   └── userdb.cpp/.h
│   └── ...
│
├── database/
│   └── SHomedb.db                      # Example SQLite database
│
├── server/
│   └── src/
│       ├── api.c/.h
│       ├── db.c/.h
│       ├── server.c/.h
│       ├── util.c/.h
│       ├── main.c
│       ├── k_program                   # Compiled server binary (example)
│       └── ...
│
└── readme.md                           # This README
```

---

## 4. Prerequisites

- **Linux environment** (e.g., Ubuntu, Debian, etc.)  
- **GCC or Clang** toolchain for compiling C/C++ code  
- **Qt Creator/Qt 5 or Qt 6** libraries for building the client  
- **SQLite3**, **cURL**, **libmicrohttpd**, and **cJSON** libraries (installed on your Linux system)  

Example (Ubuntu/Debian) installation commands:

```bash
sudo apt-get update
sudo apt-get install build-essential cmake git \
                     libsqlite3-dev libcurl4-openssl-dev \
                     libmicrohttpd-dev libcjson-dev \
                     qtbase5-dev qt5-qmake qtmultimedia5-dev \
                     libqt5charts5-dev
```

---

## 5. Building the Server on Linux

1. **Move to the source directory** (example below assumes you placed the repo under `C:\Users\Bling\Desktop\SHomeSystem`, mounted in `/mnt/c/Users/Bling/Desktop/SHomeSystem` in WSL, for instance):

   ```bash
   cd /mnt/c/Users/Bling/Desktop/SHomeSystem/server/src
   ```

2. **Compile the server files**. Below is an example of how you might compile manually:

   ```bash
   # Compile util.c
   gcc -c util.c -o util.o -I/usr/include/cjson

   # Compile db.c
   gcc -c db.c -o db.o -I/usr/include/cjson

   # Compile api.c (if needed)
   gcc -c api.c -o api.o -I/usr/include/cjson

   # Compile server.c
   gcc -c server.c -o server.o -I/usr/include/cjson

   # Compile main.c
   gcc -c main.c -o main.o -I/usr/include/cjson

   # Link everything
   gcc api.o db.o main.o server.o util.o -o k_program \
       -lmicrohttpd -lcurl -lcjson -lsqlite3
   ```

   This produces an executable (named `k_program` in the example).

---

## 6. Running the Server

1. **Make sure the SQLite database file (`SHomedb.db`) is in the correct location** (the server expects it at `../../database/SHomedb.db` by default, or you can edit the path in `server.c` / `db.c`).  
2. **Run the server**:

   ```bash
   ./k_program
   ```

   - The server starts on **port 8080**.  
   - Press **Enter** in the terminal to stop it.

---

## 7. Building the Client with Qt Creator

1. **Open Qt Creator**.  
2. **Open the `.pro` project** file located at:
   ```
   SHomeSystem/client/src/SHomeSystem.pro
   ```
3. **Configure the kit** (Qt version, compiler, etc.) in Qt Creator if needed.  
4. **Click "Build"** or use the Qt Creator build menu to compile the client.

The `.pro` file includes modules like `charts`, `sql`, and `network`, which are required for the various widgets, chart displays, and networking operations.

---

## 8. Running the Client

After successful compilation in Qt Creator:

1. **Run** the generated `SHomeSystem` application (Qt Creator’s green “Run” button).  
2. **Graphical UI** will appear with tabs for device control, data analysis, login, and registration.  
3. **Ensure your server is running** on `127.0.0.1:8080` (or the address you’ve configured in the code). Some functionalities, such as data retrieval and login, require the server to be online.

---

## 9. Key Source Files Explanation

### Server Side

- **`main.c`**  
  Entry point that calls `start_server()`.

- **`server.c` / `server.h`**  
  - Implements the microhttpd-based server, listens on port 8080.  
  - Routes incoming requests (e.g. `/user/login`, `/data/updateAirData`, etc.) to specific handler functions in `api.c`.

- **`api.c` / `api.h`**  
  - Contains logic for handling user registration, login, device data updates, and weather data fetching.  
  - Example functions: `handleUserRegister`, `handleUserLogin`, `analyzeDataAirTotalPower`, etc.

- **`db.c` / `db.h`**  
  - Manages **SQLite** operations, including `saveUser`, `getUserData`, `getDeviceData`, etc.  
  - `openDatabase` and `closeDatabase` handle the DB connection.

- **`util.c` / `util.h`**  
  - Shared helper functions for date/time retrieval, power consumption calculations, and error handling.

### Client Side

- **`SHomeSystem.pro`**  
  Qt project file listing the required modules (`core gui charts sql network`) and source files.

- **`main.cpp`**  
  Entry point for the Qt application. Launches the main `Widget`.

- **`widget.cpp/.h/.ui`**  
  Basic entry screen or main window container.

- **`tabwidget.cpp/.h/.ui`**  
  Contains multiple tabs for controlling devices (air conditioners, lights, humidifiers), setting timers, and sending requests to the server.

- **`loginview.cpp/.h/.ui`** & **`registerview.cpp/.h/.ui`**  
  Handle user login and registration with the server’s `/user/login` and `/user/register` endpoints.

- **`datawidget.cpp/.h/.ui`**  
  Displays bar charts for energy consumption data retrieved from the server.

- **`environmentwidget.cpp/.h/.ui`**  
  Displays line charts for temperature/humidity data.

- **`device.cpp/.h`**  
  Object-oriented classes for representing devices (e.g., `AirConditioner`, `Light`, `Humidifier`).

- **`executor.cpp/.h`**  
  Simulates sending commands to devices (shows pop-up messages, logs actions).

- **`sensormodule.cpp/.h`**  
  Demonstrates reading random sensor values and automatically controlling devices (e.g., turning on the air conditioner if it’s too hot).

- **`communicationinterface.cpp/.h`**  
  Illustrates how a JSON-based request might be handled within the client side, though the server portion uses C and microhttpd.

- **`userdb.cpp/.h`**  
  Example class for working with user data in the client if needed (though the official user data is stored in the server’s SQLite).

---

## 10. Troubleshooting

- **Library Linking Errors**: Ensure you have installed `libmicrohttpd-dev`, `libcurl-dev`, `libcjson-dev`, and `libsqlite3-dev`.  
- **SQLite Database Not Found**: Adjust the path in the server source code (`db.c`) or place `SHomedb.db` in the `../../database/` relative path from `server/src/`.  
- **Network Errors** (Client/Server)**: Verify the server is running on port 8080, and the client is trying to connect to `127.0.0.1:8080` (or your chosen IP/port).  
- **Qt Charts Not Displaying**: Confirm you have added `charts` to `QT += charts` in the `.pro` file and installed `libqt5charts5-dev`.

---
