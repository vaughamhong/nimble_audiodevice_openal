//
// Copyright (C) 2011 Vaugham Hong (vaughamhong@gmail.com)
//
// This file is subject to the terms and conditions defined in
// file 'license.txt', which is part of this source code package.
//

#ifndef __nimble_audiodevice_openal_audioplayer_h__
#define __nimble_audiodevice_openal_audioplayer_h__

//////////////////////////////////////////////////////////////////////////

#include <nimble/audiodevice/iaudioplayer.h>
#include <nimble/audiodevice-openal/audiobuffer.h>
#include <nimble/audiodevice-openal/common.h>

//////////////////////////////////////////////////////////////////////////

namespace nimble{
    namespace audiodevice{
        namespace openal{
            class AudioBuffer;
            
            //! Plays an audio clip
            class AudioPlayer
            : public audiodevice::IAudioPlayer{
            private:
                
                uint32_t                            m_sourceHandle;
                audiodevice::openal::AudioBuffer    *m_pAudioBuffer;
                bool                                m_hasBuffer;
                bool                                m_isPlaying;
                
            public:

                //! Constructor
                AudioPlayer();
                //! Destructor
                virtual ~AudioPlayer();
                
            public:
                
                //! Binds to an audio clip
                virtual void bindAudioBuffer(audiodevice::IAudioBuffer *pAudioBuffer);
                //! Updates our audio clip player
                virtual void update(double elapsedTime);
                
            public:
                
                //! Plays the currently bound audio clip
                virtual void play();
                //! Stops the currently bound audio clip
                virtual void stop();
                //! Returns true if we have stopped
                virtual bool isPlaying();
                
            public:
                
                //! Returns the pitch
                virtual float getPitch();
                //! Returns the gain
                virtual float getGain();
                
                //! Modifies the pitch of the output
                virtual void setPitch(float pitch);
                //! Modifies the gain of the output
                virtual void setGain(float gain);
            };
        };
    };
};

//////////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////////