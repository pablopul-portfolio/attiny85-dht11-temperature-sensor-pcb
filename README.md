# ATtiny85 Temperature & Humidity Sensor PCB

Custom PCB design for reading temperature and humidity data using an ATtiny85 microcontroller and a DHT11 sensor, with serial output via a CH340G USB-to-serial adapter.

Built to learn PCB design from scratch. Including the many mistakes made, hours spent debugging and the lessons I learned during the process.


## PCB
<div align="center">
  <table>
    <tr>
      <td>
        <img width="400" alt="pcb_photo_1" src="https://github.com/user-attachments/assets/772d363e-70c3-4aee-8bab-8a78f3a0465e"/>
      </td>
      <td>
        <img width="400" alt="pcb_photo_2" src="https://github.com/user-attachments/assets/f5bc66c8-b4fd-4b5c-b6d3-66e97176f3b4" />
      </td>
    </tr>
  </table>
</div>




## Demo
<div align="center">
  <img width="450" height="200" alt="foto demo para readme" src="https://github.com/user-attachments/assets/c4986e64-36c1-4b1f-b8c4-1b3294afc440" />
</div>


## Project Structure
```
attiny85-dht11-pcb/
├── firmware/
│   └── firmware.ino
├── hardware/
│   ├── gerbers/
│   └── EasyEDA_sensor_project.epro
├── images/
│   ├── pcb_photo.jpg
│   ├── pcb_photo_2.jpg
│   ├── pcb_schematic.png
│   └── pcb_layout.png
└── README.md
```

## Hardware

### Components
| Component | Type | Quantity |
|---|---|---|
| Microcontroller | ATtiny85-20PU | 1 |
| Temperature & Humidity Sensor | DHT11 | 1 |
| USB to UART Converter | CH340G (connector) | 1 |
| Resistors | 10K ohms | 2 |
| Ceramic Capacitors | 100nF (C0805) | 2 |
| Female Headers | - | 1 set |

### Design Tool
EasyEDA Pro - project file available in `hardware/`

### Manufacturing
Send the Gerber files (located in `hardware/gerbers/`) to a PCB manufacturer such as JLCPCB.


## Firmware

Coded in C++, the firmware reads temperature and humidity data from the DHT11 sensor every 3 seconds and sends it over to the serial converter at 4800 baud.

It's important to have in mind that I have programmed the ATtiny using an arduino uno board as an ISP. It can be done with a programmer also.

### Libraries
Install through Arduino IDE Library Manager:
- SimpleDHT by Winlin - DHT11 sensor reading
- SoftwareSerial - included with Arduino IDE

### Configuration
| Parameter | Value |
|---|---|
| Baud rate | 4800 |
| DHT11 data pin | PB2 (pin 7) |
| TX pin (to CH340G RX) | PB1 (pin 6) |

### How to program the chip:
1. Load `ArduinoISP` sketch onto an Arduino UNO (`File → Examples → ArduinoISP`)
2. Connect the ATtiny85 to the Arduino UNO.

3. In Arduino IDE select:
   - Board: `ATtiny25/45/85 (No bootloader)` - ATTinyCore by Spence Konde
   - Chip: `ATtiny85`
   - Clock: `16MHz (PLL)`
   - Programmer: `Arduino as ISP`
4. Click `Tools → Burn Bootloader`
5. Upload Sketch


## Schematics

<div align="center">
  <table>
    <tr>
      <td>
        <img width="400" alt="pcb_photo_1" src="https://github.com/user-attachments/assets/5c4991c5-c4a2-4585-88f5-87bc6cc4f5a9"/>
      </td>
      <td>
        <img width="400" alt="pcb_photo_2" src="https://github.com/user-attachments/assets/c11f5a0d-e5f2-4f25-b411-f98afb271e1b"/>
      </td>
    </tr>
  </table>
</div>


## How to use it

1. Connect the CH340G to your PC via USB
2. Open PuTTY and configure:
   - Connection type: `Serial`
   - Serial line: the COM port assigned to the CH340G
   - Speed: `4800`
3. Click Open  (temperature readings should appear)


## What I've learned

This was my first custom PCB project, and lots of things went wrong. Here are the main things I've learned:

- PCB layout matters a lot, traces routed too close to component pads make soldering harder, more space between components, especially capacitors and resistors would have helped.
- ATTinyCore by Spence Konde is more reliable than the classic David Mellis core for ATtiny85 projects. Pin numbering matches PB0, PB1, PB2 directly.
- SoftwareSerial on ATtiny85 at 16MHz works well at 4800 baud. Higher baud rates caused corrupted data (at least for me).
- Header contacts sometimes don't grip the pins properly, causing intermittent connections. Use good headers or solder the components directly to the board.
- Always connect VCC on the DHT11. Sounds obvious, but sometimes its easy to miss when debugging.
- Bad solder joints are hard to spot visually, its always good to check connections with a multimeter.
- Desoldering is harder than it looks, removing components without damaging them or the PCB traces is hard. Getting the design right the first time saves a lot of problems.
- Its a good idea to use a breadboard first to see if the project actually works before soldering everything, because maybe the errors are in the code.
- Next time I should use KiCad, as its the standard in the industry.





