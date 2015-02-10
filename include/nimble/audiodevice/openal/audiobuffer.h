//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#ifndef __nimble_audiodevice_openal_audiobuffer_h__
#define __nimble_audiodevice_openal_audiobuffer_h__

//////////////////////////////////////////////////////////////////////////

#include <nimble/audiodevice/iaudiobuffer.h>
#include <nimble/audiodevice-openal/common.h>
#include <nimble/resource/resource.h>

//////////////////////////////////////////////////////////////////////////

namespace nimble{
    namespace audiodevice{
        namespace openal{
            
            //! this class is an abstraction of a audio buffer. The AudioBuffer has no responsibilities 
            //! other than tracking the locking / unlocking mechanisms to the data.
            //! This class is not responsible for giving any context to the data.
            class AudioBuffer
            : public audiodevice::IAudioBuffer
            , public resource::Resource{
            private:
                
                uint32_t    m_audioHandle;
                uint32_t    m_frequency;
                uint32_t    m_bitrate;
                
            public:

                //! Constructor
                AudioBuffer(uint32_t frequency, uint32_t bitrate);
                //! Destructor
                virtual ~AudioBuffer();
                
            public:
                
                //! Returns the frequency of this audio buffer
                virtual uint32_t getFrequency() const;
                //! Returns the bitrate of this audio buffer
                virtual uint32_t getBitrate() const;

            public:
                
                //! copy data
                //! \param data the data to copy
                virtual void copyData(char *pData, size_t size);
                
            public:
                
                //! returns the audio clip handle
                virtual uint32_t getHandle();
            };
        };
    };
};

//////////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////////