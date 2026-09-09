import cv2
from ultralytics import YOLO

model = YOLO("yolov8n.pt")

target_classes = ["person", "bottle", "cell phone"]

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Webcam tidak dapat dibuka!")
    exit()

print("Program deteksi objek dimulai...")
print("Tekan tombol 'q' untuk keluar.")

while True:
    ret, frame = cap.read()

    if not ret:
        print("Gagal membaca frame dari webcam!")
        break

    results = model(frame, stream=True)

    for result in results:
        boxes = result.boxes

        for box in boxes:
            class_id = int(box.cls[0])

            class_name = model.names[class_id]

            confidence = float(box.conf[0])

            if class_name in target_classes:

                x1, y1, x2, y2 = box.xyxy[0]

                x1 = int(x1)
                y1 = int(y1)
                x2 = int(x2)
                y2 = int(y2)

                cv2.rectangle(
                    frame,
                    (x1, y1),
                    (x2, y2),
                    (0, 255, 0),
                    2
                )

                label = f"{class_name}: {confidence:.2f}"

                cv2.putText(
                    frame,
                    label,
                    (x1, y1 - 10),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.7,
                    (0, 255, 0),
                    2
                )

    cv2.imshow("YOLOv8n - Deteksi 3 Objek", frame)


    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()

cv2.destroyAllWindows()