#include "Animation.h"


// Animation::Animation(sf::Sprite& sprite, Type_t curr)
//     :m_sprite(sprite), m_type(curr)
// {
// }

// // void Animation::drawAnimation(sf::RenderWindow& window) //use game time or just have clock here
// // {
// //         window.clear();
// //         updateSprite();
// //         window.draw(m_sprite);
// //         window.display();     
// // }

// void Animation::updateSprite()
// {
//     if(m_clock.restart().asSeconds() > 0.04)
// 		  m_currX += 1;

//     if(m_currX > animationAmounts[m_type % 200]) //check this modulu shit!
//     {
//       m_currX = 0;
//       m_finished = true;
//     }

//     sf::IntRect newRect(m_currX * animationSizes[m_type % 200].x, 0,  animationSizes[m_type % 200].x, animationSizes[m_type % 200].y);

//     m_sprite.setTextureRect(newRect);

//     m_clock.restart();
// }

// bool Animation::finishedAnim()
// {
//     return m_finished;
// }

