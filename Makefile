capture_positives: capture_positives.cpp
	g++ -g capture_positives.cpp face_detect.cpp -o capture_positives -lopencv_core -lopencv_imgcodecs -lopencv_videoio -lopencv_imgproc -lopencv_objdetect
