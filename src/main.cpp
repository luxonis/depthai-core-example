#include <iostream>

// include depthai library
#include <depthai/depthai.hpp>

// include opencv library (Optional, used only for the following example)
#include <opencv2/opencv.hpp>


int main(){
    using namespace std;

    // Create pipeline
    dai::Pipeline pipeline;
    auto colorCam = pipeline.create<dai::node::ColorCamera>();
    auto xlinkOut = pipeline.create<dai::node::XLinkOut>();
    xlinkOut->setStreamName("preview");
    colorCam->setInterleaved(true);
    colorCam->preview.link(xlinkOut->input);
    
    // Connect to device
    dai::Device device(pipeline);

    // Get output queue
    auto preview = device.getOutputQueue("preview");

    // Start pipeline
    device.startPipeline();

    cv::Mat frame;
    while(true){
        
        // Receive 'preview' frame from device 
        auto imgFrame = preview->get<dai::ImgFrame>();
        
        // Show the received 'preview' frame
        cv::imshow("preview", cv::Mat(imgFrame->getHeight(), imgFrame->getWidth(), CV_8UC3, imgFrame->getData().data()));
        
        // Wait and check if 'q' pressed
        if(cv::waitKey(1) == 'q') return 0;
  
    }

    return 0;
}

