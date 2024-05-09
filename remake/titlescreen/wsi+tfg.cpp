/*
g++ -o wsi+tfg.run wsi+tfg.cpp /opt/github/renelindsay/Vulkan-WSIWindow/_b/WSIWindow/libWSIWindow.a -I/opt/github/renelindsay/Vulkan-WSIWindow/WSIWindow -I/opt/github/renelindsay/Vulkan-WSIWindow/WSIWindow/VulkanWrapper -I/opt/lab/lab3/textfrog/embed -L/opt/lab/.textfrog/lib/ -ltextfrog -lxcb -lxkbcommon -lX11 -lX11-xcb
LD_LIBRARY_PATH=$neoebuild_base/.textfrog/lib ./wsi+tfg.run
*/
# include "WSIWindow.h"
# include "textfrog.h"

const char * type [ ] { "up  " , "down" , "move" } ;

static textfrog tfg ;

class MyWindow : public WSIWindow {
	//--Mouse event handler--
	void OnMouseEvent ( eAction action , int16_t x , int16_t y , uint8_t btn ) {
		//	printf ( "Mouse: %s %d x %d Btn:%d\n" , type [ action ] , x , y , btn ) ;
	}

	//--Keyboard event handler--
	void OnKeyEvent ( eAction action , eKeycode keycode ) {
		//	printf ( "Key: %s keycode:%d\n" , type [ action ] , keycode ) ;
		tfg_call2 ( tfg , "OnKeyEvent" , "LL" , action , keycode ) ;
	}

	//--Text typed event handler--
	void OnTextEvent ( const char * str ) {
		// printf ( "Text: %s\n" , str ) ;
		tfg_call2 ( tfg , "OnTextEvent" , "S" , str ) ;
	}

	//--Window resize event handler--
	void OnResizeEvent ( uint16_t width , uint16_t height ) {
		printf ( "Window Resize: width=%4d height=%4d\n" , width , height ) ;
	}
} ;

int main ( ) {
	tfg = tfg_init ( 0 ) ;
	tfg_include ( tfg , "main.tfg" ) ;
	tfg_call ( tfg , "init" , 0 ) ;
	CInstance Inst ; // Create a Vulkan Instance
	MyWindow Window ; // Create a window
	Window . SetTitle ( "Vulkan" ) ; // Set window title
	Window . SetWinSize ( 640 , 480 ) ; // Set window size
	VkSurfaceKHR surface = Window . GetSurface ( Inst ) ; // Get the Vulkan surface
	while ( Window . ProcessEvents ( ) ) { } // Run until window is closed
	return 0 ;
}
