#pragma once
#include <SFML/Audio.hpp>

class SoundRenderer {
public:
    static SoundRenderer &getInstance();

    SoundRenderer(SoundRenderer &other) = delete;

    SoundRenderer &operator=(SoundRenderer &other) = delete;

    void playEatSound();

    void playCollisionSound();

    void playBackgroundMusic();

    void pauseBackgroundMusic();

    void stopBackgroundMusic();

    void setMusicVolume(float volume);

    void setSoundVolume(float volume);

private:
    SoundRenderer();

    static std::unique_ptr<SoundRenderer> instance;

    sf::SoundBuffer eatBuffer;
    sf::SoundBuffer collisionBuffer;
    sf::Sound eatSound;
    sf::Sound collisionSound;
    sf::Music backgroundMusic;

    void loadSounds();
};
