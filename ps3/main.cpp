/*
CMSC427 Spring 2015 Problem Set 3 - Ray Tracing
Brian Summers - 110656609
3/26/15
*/

#include <stdlib.h>
#include <iostream>
#include <cmath>

#include "BMPImage.h"
#include "scene.h"
#include "point3.h"

using namespace std;

//argv[0] - program name
//argv[1] - scene file name
//argv[2] - image file name
//argv[3] - image pixel width
//argv[4] - image pixel height
int main (int argc, char** argv) {
	if (argc != 5) {
		cout << "Usage: " << argv[0] << " inputFile outputFile imageWidth imageHeight" << endl;
		return 1;
	}

	int imageWidth = atoi(argv[3]);
	int imageHeight = atoi(argv[4]);

	Scene theScene;
	if (theScene.parse(argv[1]) != 1) {
		return 1;
	}

	BMPImage theImage(imageWidth, imageHeight);

	//TODO
	//raytrace the scene

	//image plane setup
	float pHeight = tan(theScene.getFieldOfViewY() / 2) * -2;
	float pWidth = pHeight * (imageWidth / imageHeight);
	Vector3 pImageCenter = Vector3(0, 0, -1);
	Vector3 pLowerLeft = pImageCenter - theScene.getEyeRight() * (pWidth / 2) - theScene.getEyeUp() * (imageHeight / 2);
	float pPixelWidth = pWidth / imageWidth, pPixelHeight = pHeight / imageHeight;

	//for each pixel in the BMPImage
	//starting world coordinate positions, top left of image is (xmin, ymax)
	int yPixPos = imageHeight / 2;
	for (int i = 0; i < imageHeight; i++) {
		yPixPos -= i;
		int xPixPos = -(imageWidth / 2);
		for (int j = 0; j < imageWidth; j++) {
			xPixPos += j;
			//cast a ray from the focal point through the pixel
			//a pixel at pixel image (i,j) has location
			Vector3 pPixelLocation = pLowerLeft + theScene.getEyeRight() * i * pPixelWidth + theScene.getEyeUp() * j * pPixelHeight;
			Vector3 ray = theScene.getEyePosition() + (pPixelLocation - theScene.getEyePosition());

			//for each shape in the scene
			float t_min = FLT_MIN;
			for (int k = 0; k < theScene.getCountShapes(); k++) {
				if (theScene.getShapes()[k])
			}
		}
	}


	if (theImage.save(argv[2]) != 1) {
		return 1;
	}

	return 0;
}