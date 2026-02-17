STM32F429ZIT6 CAN Bus Bootloader & Host UI
This repository contains a complete solution for updating STM32 firmware over CAN Bus. It includes a custom STM32F429ZIT6 Bootloader and a modern C# WPF Host Interface for managing the update process.

📌 Project Overview
The system is designed to provide a reliable way to update firmware in industrial environments where CAN Bus is the primary communication line.

Bootloader: Low-level firmware that manages flash memory sectors, CRC validation, and jump-to-application logic.

Software Update Interface: A high-performance C# WPF application that communicates via a Serial-to-CAN converter to upload binary files.

🛠 Features
🔹 STM32 Firmware (Bootloader)
Communication: CAN Bus (Custom Command-Response Protocol).

Flash Management: Safe sector erasing and 8-byte chunk writing.

Integrity Check: Custom CRC algorithm to ensure firmware validity before jumping.

Hardware: Optimized for STM32F429ZIT6 (Cortex-M4).

🔹 Host UI (C# WPF)
Modern Design: Sleek, dark-themed user interface with high-speed performance.

Real-time Tracking: Progress bar, packet counter, and status updates.

Serial-to-CAN Support: Compatible with various Serial/CAN bridge hardware.

Theming: Dynamic Dark/Light mode support.

📂 Repository Structure
Core/: STM32 Bootloader source code.

UI_5_10KW/: Source code of the Software Update Interface.

Documents/:

Logic_Diagram.drawio: System architecture and state machine (editable via draw.io).

Datasheets/: Official ST documentation for STM32F429ZIT6.

CAN.jpg: Hardware setup showing the Serial-to-CAN device used in this project.

🚀 Hardware Setup
As shown in CAN.jpg, the project utilizes a Serial-to-CAN converter.

Connect the STM32 CAN_TX / CAN_RX pins to your CAN Transceiver.

Connect the CAN_H / CAN_L lines to the Serial-to-CAN converter.

Plug the converter into your PC and select the corresponding COM port in the UI.

📡 Communication Protocol
The update process follows a strict handshake:

Handshake (0x100): Host requests entry to Bootloader.

Flash Erase (0x102): Device prepares memory sectors.

Data Flow (0x104): Firmware sent in 8-byte packets.

ACK (0x105): Device confirms each packet.

Finalize (0x106): Final CRC check and system reboot.

📄 Documentation
System logic and flowcharts are detailed in the Documents folder.

For the visual logic flow, open the .drawio file located in the documents directory.

