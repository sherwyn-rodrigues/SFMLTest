#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

 int main()
{
     bool bIsSmallWindow = false;

    //Drawing the main screen window
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML window");

    //Setting window max frame rate
    //dont use vsync and frame rate limit at the same time it makes things worse
    //window.setFramerateLimit(60);

    //Setting window position
    window.setPosition({ 0,0 });

    //Enabling Vsync
    //dont use vsync and frame rate limit at the same time it makes things worse
    window.setVerticalSyncEnabled(true);

    //Getting Screen Size
    sf::Vector2u WindowSize = window.getSize();


    //Main Loop
    while (window.isOpen())
    {

        //Checking for events
        while (const std::optional event = window.pollEvent())
        {
            //Windows close button clicked
            if (event->is<sf::Event::Closed>())
                window.close();

            //Check if any key pressed during this loop

            else if (const sf::Event::KeyPressed* KeyPress = event->getIf<sf::Event::KeyPressed>())
            {
                //Close window if escape button pressed
                if (KeyPress->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();

                if (KeyPress->scancode == sf::Keyboard::Scancode::R)
                {
                    if (bIsSmallWindow)
                    {
                        window.setSize(sf::Vector2u(100, 100));
                        bIsSmallWindow = !bIsSmallWindow;
                    }
                    else
                    {
                        window.setSize(sf::Vector2u(800, 800));
                        bIsSmallWindow = !bIsSmallWindow;
                    }
                }

            }
        }


        //getting the mouse position every frame 
        //sf::Vector2i Mouseposition = sf::Mouse::getPosition();
        //std::cout << Mouseposition.x << "," << Mouseposition.y << "\n";

        //Drawing 

        //Clear the window with black color
        window.clear(sf::Color::Black);

        //Draw everything here
        //window.draw(...);

        //Display the current frame
        window.display();
    }
}