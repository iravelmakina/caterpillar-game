#include "SoundRenderer.h"
#include <stdexcept>


SoundRenderer::SoundRenderer() {
    loadSounds();
    setMusicVolume(20);
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


void SoundRenderer::playEatSound() {
    eatSound.play();
}


void SoundRenderer::playCollisionSound() {
    collisionSound.play();
}


void SoundRenderer::playBackgroundMusic() {
    backgroundMusic.play();
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
