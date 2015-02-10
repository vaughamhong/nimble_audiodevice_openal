//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#include <nimble/audiodevice-openal/audioplayer.h>

//////////////////////////////////////////////////////////////////////////

using namespace nimble;
using namespace nimble::audiodevice::openal;

//////////////////////////////////////////////////////////////////////////

//! Constructor
AudioPlayer::AudioPlayer()
:m_sourceHandle(0)
,m_pAudioBuffer(0)
,m_hasBuffer(false)
,m_isPlaying(false){
    alGenSources(1, &m_sourceHandle);
}
//! Destructor
AudioPlayer::~AudioPlayer(){
    alDeleteSources(1, &m_sourceHandle);
}

/////////////////////////////////////////////////////////////////////////

//! Binds to an audio clip
void AudioPlayer::bindAudioBuffer(audiodevice::IAudioBuffer *pAudioBuffer){
    if(!pAudioBuffer){
        return;
    }
    if(m_isPlaying){
        stop();
    }
	m_pAudioBuffer = dynamic_cast<audiodevice::openal::AudioBuffer*>(pAudioBuffer);
    if(m_pAudioBuffer != 0){
        core::assert_error(m_pAudioBuffer != 0, "Binding an invalid OpenAL AudioBuffer");
        alSourcei(m_sourceHandle, AL_BUFFER, m_pAudioBuffer->getHandle());
        m_hasBuffer = true;
    }else{
        core::logger_warning("audio", "Invalid audio buffer for this audio player");
    }
}
//! Updates our audio clip player
void AudioPlayer::update(double elapsedTime){
    int32_t state;
    alGetSourcei(m_sourceHandle, AL_SOURCE_STATE, &state);
    m_isPlaying = (state == AL_PLAYING);
}

/////////////////////////////////////////////////////////////////////////

//! Plays the currently bound audio clip
void AudioPlayer::play(){
    
//    float orientation[6] = {0.0, 0.0, -1.0, 0.0, 1.0, 0.0};
//    alListener3f(AL_POSITION, 1000.0, 0.0, 0.0);
//    alListener3f(AL_VELOCITY, 0.0, 0.0, 0.0);
//    alListenerfv(AL_ORIENTATION, orientation);
//    
//    alSource3f(m_sourceHandle, AL_POSITION, 0.0, 0.0, 0.0);
//    alSource3f(m_sourceHandle, AL_VELOCITY, 0.0, 0.0, 0.0);
//    alSourcei(m_sourceHandle, AL_LOOPING, AL_TRUE );
    
    if(m_hasBuffer){
        m_isPlaying = true;
        alSourcePlay(m_sourceHandle);
    }
}
//! Stops the currently bound audio clip
void AudioPlayer::stop(){
    if(m_hasBuffer && !m_isPlaying){
        alSourceStop(m_sourceHandle);
        m_isPlaying = false;
    }
}
//! Returns true if we have stopped
bool AudioPlayer::isPlaying(){
    return m_isPlaying;
}

//! Returns the pitch
float AudioPlayer::getPitch(){
    float value;
    alGetSourcef(m_sourceHandle, AL_PITCH, &value);
    return value;
}
//! Returns the gain
float AudioPlayer::getGain(){
    float value;
    alGetSourcef(m_sourceHandle, AL_GAIN, &value);
    return value;
}

//////////////////////////////////////////////////////////////////////////

//! Modifies the pitch of the output
void AudioPlayer::setPitch(float pitch){
    alSourcef(m_sourceHandle, AL_PITCH, pitch);
}
//! Modifies the gain of the output
void AudioPlayer::setGain(float gain){
    alSourcef(m_sourceHandle, AL_GAIN, gain);
}

//////////////////////////////////////////////////////////////////////////