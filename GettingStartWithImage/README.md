# LIST OF MAT TYPE IN OPENCV
### from http://ninghang.blogspot.com.es/2012/11/list-of-mat-type-in-opencv.html
### credit to: https://www.blogger.com/profile/03087225378863523119

## A Mapping of Type to Numbers in OpenCV

| | C1 | C2 | C3 | C4
|---|---|---|---|---|
|CV_8U|	0|	8|	16|	24
|CV_8S|	1|	9|	17|	25
|CV_16U| 2|	10|	18|	26
|CV_16S| 3|	11|	19|	27
|CV_32S| 4|	12|	20|	28
|CV_32F| 5|	13|	21|	29
|CV_64F| 6|	14|	22|	30


### Unsigned 8bits uchar 0~255
IplImage: IPL_DEPTH_8U
Mat: CV_8UC1, CV_8UC2, CV_8UC3, CV_8UC4

### Signed 8bits char -128~127
IplImage: IPL_DEPTH_8S
Mat: CV_8SC1，CV_8SC2，CV_8SC3，CV_8SC4

### Unsigned 16bits ushort 0~65535
IplImage: IPL_DEPTH_16U
Mat: CV_16UC1，CV_16UC2，CV_16UC3，CV_16UC4

### Signed 16bits short -32768~32767
IplImage: IPL_DEPTH_16S
Mat: CV_16SC1，CV_16SC2，CV_16SC3，CV_16SC4

### Signed 32bits int -2147483648~2147483647
IplImage: IPL_DEPTH_32S
Mat: CV_32SC1，CV_32SC2，CV_32SC3，CV_32SC4

### Float 32bits float -1.18*10-38~3.40*10-38 
IplImage: IPL_DEPTH_32F
Mat: CV_32FC1，CV_32FC2，CV_32FC3，CV_32FC4

### Double 64bits double 
Mat: CV_64FC1，CV_64FC2，CV_64FC3，CV_64FC4

### Unsigned 1bit bool
IplImage: IPL_DEPTH_1U