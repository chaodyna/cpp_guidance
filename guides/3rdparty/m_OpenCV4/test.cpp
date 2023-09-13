#include <opencv2/imgcodecs/legacy/constants_c.h>
#include <opencv2/highgui.hpp>
#include <iostream>
int main( int argc, char** argv ) {
    cv::Mat image;
    image = cv::imread("/home/lilongen/downloads/openMMLab/downloads/mmpose/demo/resources/sunglasses.jpg" , CV_LOAD_IMAGE_COLOR);	      
    if(! image.data ) {
        std::cout <<  "Could not open or find the image" << std::endl ;
	    return -1;
    }

    std::cout << "image wide: "<< image.cols << ",image high: " << image.rows << ",image channels: "<< image.channels() << std::endl;
    /* display image
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", image );		    
    cv::waitKey(0);
    */
    size_t y,x;// y is row, x is col
    int c;     // c is channel
    y = x = 250;
    c = 2;
    // row_ptr is the head point of y row
    unsigned char *row_ptr = image.ptr<unsigned char>(y);
    // data_ptr points to pixel data
    unsigned char *data_ptr = &row_ptr[x * image.channels()]; 
    unsigned char data =  data_ptr[c];

    // use cv::Mat::at() to get the pixel value
    // unsigned char is not printable
    // std::cout << std::isprint(data)<<std::isprint(image.at<cv::Vec3b>(y,x)[c]) << std::endl;
    std::cout << "pixel value at y, x ,c"<<static_cast<unsigned>(image.at<cv::Vec3b>(y,x)[c]) << std::endl;
    return 0;
}

