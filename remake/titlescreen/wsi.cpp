/*
g++ -o wsi.run wsi.cpp /opt/github/renelindsay/Vulkan-WSIWindow/_b/WSIWindow/libWSIWindow.a -I/opt/github/renelindsay/Vulkan-WSIWindow/WSIWindow -I/opt/github/renelindsay/Vulkan-WSIWindow/WSIWindow/VulkanWrapper -lxcb -lxkbcommon -lX11 -lX11-xcb
*/
# include "WSIWindow.h"

const char * type [ ] { "up  " , "down" , "move" } ;

class MyWindow : public WSIWindow {
	//--Mouse event handler--
	void OnMouseEvent ( eAction action , int16_t x , int16_t y , uint8_t btn ) {
		//	printf ( "Mouse: %s %d x %d Btn:%d\n" , type [ action ] , x , y , btn ) ;
	}

	//--Keyboard event handler--
	void OnKeyEvent ( eAction action , eKeycode keycode ) {
		printf ( "Key: %s keycode:%d\n" , type [ action ] , keycode ) ;
	}

	//--Text typed event handler--
	void OnTextEvent ( const char * str ) {
		printf ( "Text: %s\n" , str ) ;
	}

	//--Window resize event handler--
	void OnResizeEvent ( uint16_t width , uint16_t height ) {
		printf ( "Window Resize: width=%4d height=%4d\n" , width , height ) ;
	}
} ;

int main ( ) {
	CInstance Inst ; // Create a Vulkan Instance
	MyWindow Window ; // Create a window
	Window . SetTitle ( "Vulkan" ) ; // Set window title
	Window . SetWinSize ( 640 , 480 ) ; // Set window size
	VkSurfaceKHR surface = Window . GetSurface ( Inst ) ; // Get the Vulkan surface
	while ( Window . ProcessEvents ( ) ) { } // Run until window is closed
	return 0 ;
}
