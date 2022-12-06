#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

// Window Management
float windowScale = 0.8f;
int currentWindowWidth = VideoMode::getDesktopMode().width*windowScale;
int currentWindowHeight = VideoMode::getDesktopMode().height*windowScale;
VideoMode desktop(currentWindowWidth, currentWindowHeight);
float aspect_ratio = currentWindowHeight / static_cast<float>(currentWindowWidth);
RenderWindow window(desktop, "Packet Chess", Style::Close);