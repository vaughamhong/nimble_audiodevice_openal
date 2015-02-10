//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#include <nimble/audiodevice-openal/audiodevice.h>
#include <nimble/audiodevice-openal/audiobuffer.h>
#include <nimble/audiodevice-openal/audioplayer.h>

//////////////////////////////////////////////////////////////////////////

using namespace nimble;
using namespace nimble::audiodevice::openal;

//////////////////////////////////////////////////////////////////////////

//! Constructor
AudioDevice::AudioDevice(){
    m_pDevice = alcOpenDevice(0);
    m_pContext = alcCreateContext(m_pDevice, 0);
    alcMakeContextCurrent(m_pContext);
}

//! Destructor
AudioDevice::~AudioDevice(){
	alcDestroyContext(m_pContext);
	alcCloseDevice(m_pDevice);
}

//////////////////////////////////////////////////////////////////////////

//! creates a audio clip
//! \return a audio clip
audiodevice::IAudioBuffer* AudioDevice::createAudioBuffer(uint32_t frequency, uint32_t bitrate){
    return new /*( audio dynamic )*/ audiodevice::openal::AudioBuffer(frequency, bitrate);
}
//! creates a audio clip player
//! \return a audio clip player
audiodevice::IAudioPlayer* AudioDevice::createAudioPlayer(){
    return new /*( audio dynamic )*/ audiodevice::openal::AudioPlayer();
}

//////////////////////////////////////////////////////////////////////////

