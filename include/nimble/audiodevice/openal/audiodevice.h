//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#ifndef __nimble_audiodevice_openal_audiodevice_h__
#define __nimble_audiodevice_openal_audiodevice_h__

//////////////////////////////////////////////////////////////////////////

#include <nimble/audiodevice/iaudiodevice.h>
#include <nimble/audiodevice-openal/common.h>

//////////////////////////////////////////////////////////////////////////

namespace nimble{
    namespace audiodevice{
        namespace openal{
            
            //! audio device
            class AudioDevice
            : public audiodevice::IAudioDevice{
            private:
                
                ALCdevice   *m_pDevice;
                ALCcontext  *m_pContext;
                
            public:
                
                //! Constructor
                AudioDevice();
                //! Destructor
                virtual ~AudioDevice();
                
            public:
                
                //! creates a audio clip
                //! \return a audio clip
                virtual audiodevice::IAudioBuffer* createAudioBuffer(uint32_t frequency, uint32_t bitrate);
                //! creates a audio clip player
                //! \return a audio clip player
                virtual audiodevice::IAudioPlayer* createAudioPlayer();
            };
        };
    };
};

//////////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////////
