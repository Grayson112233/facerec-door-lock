// Grayson Pike, 2018

#include "face_detect.hpp"

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

#define HAAR_FACES_FILE "cascades/haarcascade_frontalface_alt.xml"
#define HAAR_SCALE_FACTOR  1.1
#define HAAR_MIN_NEIGHBORS 4
#define HAAR_FLAGS 0
#define HAAR_MIN_SIZE_X 30
#define HAAR_MIN_SIZE_Y 30


/*
	Utility function to detect faces in an image
	Returns a vector of Rects with regions of detected faces in a given image
*/
std::vector<cv::Rect> detect_faces(cv::Mat image) {

	// Create a Haar Cascade Classifier configured for frontal faces
	cv::CascadeClassifier haar_faces_classifier(HAAR_FACES_FILE);

	// Identify all the regions with faces in the image
	std::vector<cv::Rect> face_regions;
	haar_faces_classifier.detectMultiScale(
			image,
			face_regions,
			HAAR_SCALE_FACTOR,
			HAAR_MIN_NEIGHBORS,
			cv::CASCADE_SCALE_IMAGE,
			cv::Size(HAAR_MIN_SIZE_X, HAAR_MIN_SIZE_Y)
		);

	return face_regions;

}