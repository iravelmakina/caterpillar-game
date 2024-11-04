#pragma once
#include <SFML/Audio.hpp>

class SoundRenderer {
public:
    SoundRenderer();

    void playEatSound();

    void playCollisionSound();

    void playBackgroundMusic();

    void stopBackgroundMusic();

    void setMusicVolume(float volume);

    void setSoundVolume(float volume);

private:
    sf::SoundBuffer eatBuffer;
    sf::SoundBuffer collisionBuffer;

    sf::Sound eatSound;
    sf::Sound collisionSound;

    sf::Music backgroundMusic;

    void loadSounds();
};
