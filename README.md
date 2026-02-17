# STM32F429ZIT6_BOOTLOADER

STM32 CAN Bus bootloader project demonstrating reliable firmware update
using **Custom CAN Protocol** in **Bootloader Mode**.

This project integrates flash sector management, firmware integrity
verification, and safe application jump logic for industrial firmware
update scenarios.

------------------------------------------------------------------------

## 📌 Overview

This project demonstrates how to use: - **CAN Bootloader
Communication:** Firmware update over CAN Bus using custom packet
protocol. - **Flash Memory Control:** Application sector erase and write
management. - **Firmware Integrity Verification:** CRC validation before
executing firmware. - **Bootloader Safety Architecture:** Separate
bootloader and application memory structure.

------------------------------------------------------------------------

## 🧠 Concepts Covered

-   **Bootloader Flash Architecture:** Separate Bootloader and
    Application flash regions.
-   **CAN Packet Firmware Transfer:** Segmented firmware transmission
    using 8-byte CAN frames.
-   **Flash Safety Management:** Controlled erase and write sequence to
    prevent corruption.
-   **CRC Validation:** Ensuring firmware integrity before application
    execution.
-   **Safe Jump Implementation:** Vector table relocation and MSP
    initialization before jump.

------------------------------------------------------------------------

## 🛠 Hardware

-   **MCU:** STM32F429ZIT6 (LQFP144 package)
-   **Communication:** External CAN Transceiver
-   **Interface Device:** Serial-to-CAN Converter (Used during testing)

------------------------------------------------------------------------

## 🔌 CAN Communication (Protocol Concept)

  Command           Description
  ----------------- -------------------------------------
  **Handshake**     Bootloader activation request
  **Flash Erase**   Application flash erase operation
  **Data Packet**   Firmware data transfer
  **ACK**           Packet receive confirmation
  **Finalize**      CRC validation and application jump

------------------------------------------------------------------------

## ▶️ How It Works

1.  **Boot Decision:** MCU decides bootloader or application at reset.
2.  **Handshake:** Host requests bootloader mode via CAN communication.
3.  **Flash Preparation:** Application sectors are erased safely.
4.  **Firmware Transfer:** Firmware is transmitted using CAN packets.
5.  **CRC Verification:** Firmware integrity is verified before
    execution.
6.  **Application Jump:** Bootloader safely transfers execution to
    application.

------------------------------------------------------------------------

## 🧪 Testing

-   **CAN Communication Stability:** Verified under continuous firmware
    streaming.
-   **Flash Reliability:** Multiple erase/write cycles tested
    successfully.
-   **CRC Protection:** Corrupted firmware images correctly rejected.
-   **Boot Safety:** Verified correct vector relocation and execution.

------------------------------------------------------------------------

## 📸 Hardware Configuration

The following CAN interface hardware was used during development:

![CAN Device](CAN.jpeg)

## Message Sequence And Details

![Drowio](Documents/BootloaderEN.drawio)


