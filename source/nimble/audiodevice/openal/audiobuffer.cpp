//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#include <nimble/audiodevice-openal/audiobuffer.h>

//////////////////////////////////////////////////////////////////////////

using namespace nimble;
using namespace nimble::audiodevice::openal;

//////////////////////////////////////////////////////////////////////////

//! Constructor
AudioBuffer::AudioBuffer(uint32_t frequency, uint32_t bitrate)
:m_audioHandle(0)
,m_frequency(frequency)
,m_bitrate(bitrate){
    alGenBuffers(1, &m_audioHandle);
}
//! Destructor
AudioBuffer::~AudioBuffer(){
    alDeleteBuffers(1, &m_audioHandle);
}

//! Returns the frequency of this audio buffer
uint32_t AudioBuffer::getFrequency() const{
    return m_frequency;
}
//! Returns the bitrate of this audio buffer
uint32_t AudioBuffer::getBitrate() const{
    return m_bitrate;
}

//////////////////////////////////////////////////////////////////////////

//! copy data
//! \param data the data to copy
void AudioBuffer::copyData(char *pData, size_t size){
    // TODO: Consider replacing copyData with a lock interface
    alBufferData(m_audioHandle, AL_FORMAT_STEREO16, pData, size, m_frequency);
}

//////////////////////////////////////////////////////////////////////////

//! returns the audio clip handle
uint32_t AudioBuffer::getHandle(){
    return m_audioHandle;
}

//////////////////////////////////////////////////////////////////////////