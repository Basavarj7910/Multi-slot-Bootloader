# STM32F407VG Multi-Slot Bootloader

This project is a custom **multi-slot bootloader** written from scratch for the **STM32F407VG** microcontroller. The bootloader supports selecting one of multiple user applications stored in flash memory based on button input and UART communication at boot.

---

## 🚀 What is a Bootloader?

A **bootloader** is a small program that runs before any application code starts executing on an embedded device. It is responsible for initializing the system and deciding which application (firmware) to load into execution.

---

## 🔧 Why Use a Bootloader?

Bootloaders are essential in embedded systems for the following reasons:

- 🧩 **Application switching:** Enables selecting between different firmware versions or application modes.
- 💾 **Memory management:** Manages flash layout for multiple apps.
- 🛠️ **Firmware upgrades:** Can be extended to support OTA or serial upgrades.
- 🧪 **Testing/debugging:** Easily switch between factory test code, debug code, and production code.
- 🧼 **Recovery/factory reset:** Restore the default firmware in case of issues.

---

## 📦 Features

- Support for **3 different applications**:
  - `Default App`
  - `App 1` (User slot)
  - `App 2` (Factory slot)
- **Button-based boot selection** using onboard USER button.
- **UART-based app selection** when button is pressed.
- Times out in 5 seconds and loads `Default App` if no button is pressed.
- Runs entirely on bare-metal STM32F407VG.

---

## 🔁 Boot Flow Overview

                                         +---------------------------+
                                         |     Power On / Reset      |
                                         +---------------------------+
                                                      |
                                                      v
                                         +---------------------------+
                                         |   Initialize Hardware     |
                                         +---------------------------+
                                                      |
                                                      v
                                   +---------------------------------------------+
                                   | Wait 5s: Is USER Button Pressed?            |
                                   +---------------------------------------------+
                                        |                                |
                                        | No                             | Yes
                                        v                                v
                           +--------------------------+     +--------------------------+
                           |   Jump to Default App    |     |  Prompt UART Input       |
                           +--------------------------+     +--------------------------+
                                                                        |
                                                                        v
                                                         +------------------------------+
                                                         | Wait for Key: '1' or '2'     |
                                                         +------------------------------+
                                                             |                    |
                                                             | '1'                | '2'
                                                             v                    v
                                            +--------------------------+   +--------------------------+
                                            |   Jump to App1           |   |   Jump to App2           |
                                            +--------------------------+   +--------------------------+



---

## 🧠 Flash Memory Layout

| Application   | Flash Address (Example) |
|---------------|-------------------------|
| Bootloader    | `0x08000000`            |
| Default App   | `0x08020000`            |
| App1 (User)   | `0x08060000`            |
| App2 (Factory)| `0x080a0000`            |

*(Make sure the linker scripts for each app match the offset above.)*







