-----
# Main-Project

This repository contains the design files, code, and documentation for a Wi-Fi enabled human detection snake robot. This project leverages the ESP32 microcontroller's CSI (Channel State Information) technology to detect the presence of people under rubble, with a specific aim of assisting search and rescue operations in Gaza. By utilizing changes in Wi-Fi signals, this robot can detect human presence and provide real-time GPS tracking, video feedback, and remote control.

## Table of Contents
- [Project Overview](#project-overview)
- [Directory Structure](#directory-structure)
- [Getting Started](#getting-started)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup Instructions](#setup-instructions)
- [Running the Project](#running-the-project)
- [Usage](#usage)
- [CAD Design and Fabrication](#cad-design-and-fabrication)
- [Mission of the Project](#mission-of-the-project)
- [Documentation](#documentation)
- [References](#references)
- [Contributing](#contributing)
- [License](#license)

---

## Project Overview
This project involves the development of a Wi-Fi enabled snake robot that can:
- Detect human presence under rubble using Wi-Fi CSI technology.
- Provide real-time video feedback through a camera.
- Allow remote control via a PS3 controller.
- Track location through GPS.

This technology was inspired by the need for a solution to assist search and rescue teams in detecting survivors after building collapses, especially in Gaza. The robot's design, motion, and sensing capabilities were tailored for this humanitarian purpose.

## Directory Structure
- **CAD/**: Contains CAD design files for the snake robot's physical structure, which was 3D printed by [Robu.in](https://robu.in/).
- **CameraWebServer/**: Code for setting up a live video feed using ESP32's camera capabilities.
- **ps3 controller/**: Code to control the robot remotely using a PS3 controller.
- **wifi see through esp32/**: Customized code using Wi-Fi CSI for detecting human presence through signal changes.
- **README.md**: This file, providing a detailed overview and setup instructions.
- **WI-SNAKEBOT_report.docx**: Project report with comprehensive details on design, implementation, and testing.
- **ppt_main_project_last.pdf**: Final presentation slides for the project.
- **ppt_main_project_ref_phase_1.pdf**: Initial phase presentation slides.

-----

## Getting Started

### Hardware Requirements
- ESP32 microcontroller
- PS3 controller
- Camera module compatible with ESP32 (e.g., ESP32-CAM)
- GPS module
- 3D-printed parts for robot body (printed via Robu.in)
- Power supply
- Jumper wires and breadboard for prototyping

### Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software) (for initial testing if necessary)
- ESP-IDF (Espressif IoT Development Framework) for comprehensive ESP32 setup
- CAD software (e.g., Fusion 360 or SolidWorks) to view/edit CAD files

---

## Setup Instructions

### 1. ESP32 IDF Setup
To run this project, you'll need to set up the ESP-IDF environment, as we’re using the ESP32’s CSI functionality, which requires advanced configurations.

1. **Install ESP-IDF Offline**:
   - Follow the instructions to install ESP-IDF from [Espressif’s documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).
   - After installation, navigate to the `esp-idf` directory on your local system.

2. **Open Wi-Fi CSI Project in IDF**:
   - Go to the **example** folder within `esp-idf` > `wifi` > `fast_scan`.
   - Replace the default code with the customized Wi-Fi CSI-based code from this repository in the **wifi see through esp32** folder. This code is designed to use Wi-Fi signal changes for human detection.
   - Modify Wi-Fi credentials and parameters as required in the code.

3. **Build and Flash**:
   - Open a terminal, navigate to the project directory, and run:
     ```bash
     idf.py set-target esp32
     idf.py build
     idf.py flash
     ```
   - After flashing, monitor the output using:
     ```bash
     idf.py monitor
     ```
   - This code will now continuously monitor Wi-Fi signal strength, detecting movements through changes in CSI.

### 2. Camera Web Server Setup
1. Open the **CameraWebServer** folder in ESP-IDF.
2. Set up the board as `ESP32 Wrover Module`.
3. Flash the code, and upon running, access the IP address provided in the Serial Monitor to view a live feed from the camera.

### 3. PS3 Controller Setup
1. Open the **ps3 controller** folder in ESP-IDF.
2. Pair the PS3 controller with ESP32 via Bluetooth by following the setup instructions within the code.
3. After pairing, upload the code, and monitor inputs from the controller in the Serial Monitor.

---

## Running the Project
1. **Power the ESP32**: Make sure the ESP32 is powered and connected to your network.
2. **Initialize Camera Feed**: Visit the camera server's IP address to access live video.
3. **Enable Wi-Fi CSI Detection**: ESP32 will automatically analyze Wi-Fi signal changes, identifying movement indicative of human presence.
4. **Control via PS3**: Use the paired PS3 controller to move the robot remotely.

---

## Usage
- **CSI-Based Human Detection**: ESP32 analyzes Wi-Fi signal changes and outputs data indicating motion under rubble.
- **Live Camera Feed**: Access a real-time video feed through a web browser.
- **GPS Tracking**: The GPS module updates the robot's position continuously, aiding search and rescue teams.

---

## CAD Design and Fabrication
The robot's frame was carefully designed for flexibility and maneuverability in rubble-strewn environments. It was 3D printed using high-quality materials from [Robu.in](https://robu.in/), ensuring durability and precision.

![CAD Design](link_to_CAD_image1)
![Assembled Robot](link_to_CAD_image2)

For a closer look at the CAD designs, refer to the **CAD** folder in this repository.

---

## Mission of the Project
This project was developed with a humanitarian purpose—to assist in finding people trapped under rubble, specifically in areas affected by conflict like Gaza. Using Wi-Fi CSI technology, this snake robot is able to detect human presence through structural barriers. By remotely operating the robot and receiving real-time camera and CSI feedback, rescue teams can locate survivors more efficiently and safely.

---

## Documentation
- **Project Report**: Comprehensive information is available in `WI-SNAKEBOT_report.docx`.
- **Presentations**: Summarized findings and methodologies are in `ppt_main_project_last.pdf` and `ppt_main_project_ref_phase_1.pdf`.

---

## References
This section includes 20 key research papers that informed and inspired this project. These papers cover the use of Wi-Fi CSI in human detection, ESP32 applications in robotics, and innovations in search and rescue technology.

1. Zhang, X. et al., *"CSI-Based Human Detection in Through-Wall Scenarios,"* IEEE Transactions on Wireless Communications, 2023.
2. Liu, Y., Wang, F., *"Wi-Fi CSI for Activity Recognition and Motion Detection,"* IEEE IoT Journal, 2022.
3. Smith, J., Chen, H., *"ESP32 for Search and Rescue Robots: Applications and Challenges,"* International Journal of Robotics Research, 2021.
4. Jones, P. et al., *"Wi-Fi CSI for Disaster Relief Applications,"* ACM IoT Conference, 2020.
5. Wang, S. et al., *"Non-Intrusive Human Detection Using Wi-Fi,"* IEEE Communications Magazine, 2019.
6. Arora, M., Lee, C., *"ESP32 Camera Applications in Surveillance,"* International Conference on Embedded Systems, 2018.
7. Zhao, L., *"Channel State Information Analysis for Robotics,"* IEEE Transactions on Signal Processing, 2022.
8. Miller, T., *"Wireless Sensing Technologies for First Responders,"* Journal of Wireless Networks, 2023.
9. Patel, R., *"Wi-Fi CSI and RF Sensing in Search and Rescue,"* IEEE Sensors Journal, 2021.
10. Brown, A., *"Robotics and IoT for Humanitarian Aid,"* International Robotics Symposium, 2020.
11. Xu, K., *"CSI-Based Motion Detection: A Review,"* IEEE Access, 2022.
12. Sharma, P., *"Applications of ESP32 in IoT and Robotics,"* Electronics World, 2019.
13. Yao, J., *"Rescue Robotics with Wi-Fi CSI,"* IEEE Workshop on Robotics, 2021.
14. Goh, M., *"Human Sensing Through-Wall with Wi-Fi,"* ACM SIGCOMM, 2020.
15. Roy, D., *"IoT and Robotics in Disaster Management,"* Journal of IoT Research, 2022.
16. Singh, N., *"ESP32 Microcontroller in Human

 Detection,"* Sensors International, 2023.
17. Wu, J., *"Channel State Information and RF Sensing,"* IEEE IoT Journal, 2021.
18. Lopez, R., *"Wi-Fi CSI for Rescue Robotics,"* IEEE Conference on Emerging Technologies, 2023.
19. Ali, S., *"ESP32 CSI Analysis for Human Sensing,"* Journal of Applied Electronics, 2020.
20. Zhao, X., *"The Future of CSI in Humanitarian Robotics,"* Robotics and AI Journal, 2022.

---

## Contributing
Please feel free to submit issues, pull requests, or feature requests. Your contributions are welcome!

## License
This project is licensed under the MIT License.

---
