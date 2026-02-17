# STM32F429ZIT6 CAN Bus Bootloader

An STM32 firmware update solution utilizing a **Custom CAN Protocol** in **Bootloader Mode**. 

This project integrates flash sector management, firmware integrity verification, and secure application jump logic designed for industrial update scenarios.

---

## 📌 Overview

This project demonstrates the implementation of:
* **CAN Communication:** Firmware updates over CAN Bus using a custom packet protocol.
* **Flash Memory Control:** Application sector erase and write management.
* **Integrity Verification:** CRC validation before executing firmware.
* **Architecture:** Separate bootloader and application memory structure.

---

## 🧠 Concepts Covered

* **Flash Architecture:** Dedicated regions for Bootloader and Application code.
* **Segmented Transfer:** Firmware transmission using 8-byte CAN frames.
* **Safety Management:** Controlled erase/write sequences to prevent memory corruption.
* **Jump Implementation:** Vector table relocation and MSP initialization prior to execution.

---

## 🛠 Hardware

* **MCU:** STM32F429ZIT6 (LQFP144 package)
* **Communication:** External CAN Transceiver
* **Interface:** Serial-to-CAN Converter (Used for development/testing)

---

## 🔌 CAN Communication Protocol

| Command | Description |
| :--- | :--- |
| **Handshake** | Bootloader activation request |
| **Flash Erase** | Application flash erase operation |
| **Data Packet** | Firmware data transfer |
| **ACK** | Packet receive confirmation |
| **Finalize** | CRC validation and application jump |

---

## ▶️ Execution Flow

1. **Boot Decision:** MCU determines the mode (Bootloader vs. Application) at reset.
2. **Handshake:** Host requests access via CAN communication.
3. **Flash Prep:** Application sectors are safely erased.
4. **Data Transfer:** Firmware is transmitted via segmented CAN packets.
5. **CRC Check:** Integrity is verified to ensure the image is not corrupted.
6. **Application Jump:** Execution is securely transferred to the main application.

---

## 📊 Documentation & Setup

Detailed message sequences and hardware configurations used during development:

![CAN Device](CAN.jpeg)

* **Sequence Diagram:** Refer to `Documents/BootloaderEN.drawio` for the full logic flow.
* **Testing:** Verified through continuous streaming, flash cycle stress tests, and CRC rejection of corrupted images.

---

## 🔗 Related Resources

For the host-side interaction, check out the companion interface:

> 🖥 **Update Interface:** [erenozkan94/Software_Update_Interface](https://github.com/erenozkan94/Software_Update_Interface)
