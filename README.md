# AI-Powered Color Memory Game & Gesture Recognition Models 🎮🤖

An innovative, touch-free interactive system that combines **Computer Vision** and **Embedded Systems**. Players reproduce LED sequences shown by an Arduino using specific hand gestures, with a unique "Mouth Open" trigger for sending commands.

---

## 📄 Academic Research: Sign-Language Model Comparison

This project includes a detailed academic report comparing three major models for hand-gesture and sign-language recognition. The models were evaluated based on Accuracy, F1-Score, Precision, and Recall.

### Performance Metrics
| Model | Accuracy | F1-Score | Precision | Recall |
| :--- | :--- | :--- | :--- | :--- |
| **MediaPipe Hands** | 94% | 0.96 | 0.97 | 0.95 |
| **GestureNet** | 89–94% | 0.88–0.93 | 0.92 | 0.90 |
| **WLASL Models** | 33–35% | 0.52 | 0.55 | 0.50 |

### Key Findings & Use Cases
* **MediaPipe Hands:** Best for precise landmark extraction and tracking.
* **GestureNet (NVIDIA):** Best for simple static gesture commands like OK, Stop, Yes, and No.
* **WLASL Models:** Most appropriate for recognizing full ASL vocabulary words despite the high complexity.

**Conclusion:** MediaPipe is the best for precise hand tracking, GestureNet for static gesture classification, and WLASL models for full word-level sign-language recognition.

---

## 🚀 Game Features & Technologies
- **Real-time Hand Tracking**: Uses MediaPipe to detect 21 hand landmarks.
- **Facial Expression Control**: Commands are sent to the Arduino only when the mouth is open.
- **Python & C++ (Arduino)**: Core logic, Computer Vision, and LED sequence control.

## 🖐️ Gesture Mapping
- **Green**: Both hands open.
- **Blue**: Left hand raised.
- **Orange**: Right hand raised.
- **Yellow**: One closed fist.
- **Red**: One open hand.
- **White**: Both hands closed.
