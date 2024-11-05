#include "SoundRenderer.h"


std::unique_ptr<SoundRenderer> SoundRenderer::instance = nullptr;


SoundRenderer &SoundRenderer::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<SoundRenderer>(new SoundRenderer());
    }
    return *instance;
}


void SoundRenderer::playEatSound() {
    eatSound.play();
}


void SoundRenderer::playCollisionSound() {
    collisionSound.play();
}


void SoundRenderer::playBackgroundMusic() {
    backgroundMusic.play();
}

void SoundRenderer::pauseBackgroundMusic() {
    backgroundMusic.pause();
}

void SoundRenderer::stopBackgroundMusic() {
    backgroundMusic.stop();
}


void SoundRenderer::setMusicVolume(const float volume) {
    backgroundMusic.setVolume(volume);
}


void SoundRenderer::setSoundVolume(const float volume) {
    eatSound.setVolume(volume);
    collisionSound.setVolume(volume);
}


SoundRenderer::SoundRenderer() {
    loadSounds();
    setMusicVolume(10);
}


void SoundRenderer::loadSounds() {
    if (!eatBuffer.loadFromFile("res/sounds/eat.wav")) {
        throw std::runtime_error("Failed to load eat sound");
    }
    eatSound.setBuffer(eatBuffer);

    if (!collisionBuffer.loadFromFile("res/sounds/collision.wav")) {
        throw std::runtime_error("Failed to load collision sound");
    }
    collisionSound.setBuffer(collisionBuffer);

    if (!backgroundMusic.openFromFile("res/sounds/backgroundMusic.wav")) {
        throw std::runtime_error("Failed to load background music");
    }
    backgroundMusic.setLoop(true);
}