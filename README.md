# 🌿 SmartCooling

Hệ thống làm mát khu vực ngoài trời thông minh dành cho trường học.

## 📌 Mô tả

SmartCooling là mô hình tự động giúp tạo môi trường mát mẻ tại khu vực ghế đá hoặc mái che trong trường học.

Hệ thống có khả năng:

- ☀️ Phát hiện nắng
- 🌧️ Phát hiện mưa
- 🌡️ Đo nhiệt độ và độ ẩm
- 👤 Phát hiện có người
- 🏠 Điều khiển mái che tự động
- 💨 Điều khiển hệ thống phun sương
- 📟 Hiển thị trạng thái trên LCD

---

## 🏗️ Kiến trúc

```
SensorManager
      │
      ▼
 SensorData
      │
      ▼
SmartController
      │
      ▼
 SystemState
      │
      ▼
DeviceManager
 ├── RoofController
 ├── MistController
 └── DisplayManager
```

---

## ⚙️ Điều kiện hoạt động

| Điều kiện | Mái | Phun sương |
|-----------|-----|------------|
| ☀️ Nắng | Mở | Tắt |
| ☀️ Nắng + Nóng + Có người | Mở | Bật |
| 🌧️ Mưa | Mở | Tắt |
| ☁️ Âm u | Đóng | Tắt |
| ☁️ Âm u + Nóng + Có người | Đóng | Bật |
| 🌦️ Nắng + Mưa | Mở | Tắt |

---

## 📦 Linh kiện

- Arduino Uno
- DHT22
- BH1750
- Cảm biến mưa
- RCWL-0516 Radar
- Servo MG996R
- Relay 5V
- Máy tạo sương 5V
- LCD I2C

---

## 📁 Cấu trúc dự án

```
include/
├── config/
├── controller/
├── devices/
├── models/
└── sensors/

src/
├── controller/
├── devices/
├── sensors/
└── main.cpp
```

---

## 🚀 Tiến độ

- [x] Project Structure
- [x] Project Architecture
- [x] SmartController
- [x] Weather Hysteresis
- [x] Simulation
- [x] Device Layer
- [x] Sensor Manager
- [ ] Arduino Integration
- [ ] LCD Integration
- [ ] Servo Control
- [ ] Relay Control
- [ ] Dashboard

---

## 👨‍💻 Tác giả

Linh