/*****************************************************************
|
|    Bento4 - C API Implementation
|
|    Copyright 2002-2008 Gilles Boccon-Gibod & Julien Boeuf
|
|
|    This file is part of Bento4/AP4 (MP4 Atom Processing Library).
|
|    Unless you have obtained Bento4 under a difference license,
|    this version of Bento4 is Bento4|GPL.
|    Bento4|GPL is free software; you can redistribute it and/or modify
|    it under the terms of the GNU General Public License as published by
|    the Free Software Foundation; either version 2, or (at your option)
|    any later version.
|
|    Bento4|GPL is distributed in the hope that it will be useful,
|    but WITHOUT ANY WARRANTY; without even the implied warranty of
|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|    GNU General Public License for more details.
|
|    You should have received a copy of the GNU General Public License
|    along with Bento4|GPL; see the file COPYING.  If not, write to the
|    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
|    02111-1307, USA.
|
 ****************************************************************/

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "Bento4C.h"
#include "Ap4.h"

/*----------------------------------------------------------------------
|   constants
+---------------------------------------------------------------------*/
const int AP4_FILE_BYTE_STREAM_MODE_READ       = AP4_FileByteStream::STREAM_MODE_READ;
const int AP4_FILE_BYTE_STREAM_MODE_WRITE      = AP4_FileByteStream::STREAM_MODE_WRITE;
const int AP4_FILE_BYTE_STREAM_MODE_READ_WRITE = AP4_FileByteStream::STREAM_MODE_READ_WRITE;

const int AP4_TRACK_TYPE_UNKNOWN = AP4_Track::TYPE_UNKNOWN;
const int AP4_TRACK_TYPE_AUDIO   = AP4_Track::TYPE_AUDIO;
const int AP4_TRACK_TYPE_VIDEO   = AP4_Track::TYPE_VIDEO;
const int AP4_TRACK_TYPE_SYSTEM  = AP4_Track::TYPE_SYSTEM;
const int AP4_TRACK_TYPE_HINT    = AP4_Track::TYPE_HINT;
const int AP4_TRACK_TYPE_TEXT    = AP4_Track::TYPE_TEXT;
const int AP4_TRACK_TYPE_JPEG    = AP4_Track::TYPE_JPEG;
const int AP4_TRACK_TYPE_RTP     = AP4_Track::TYPE_RTP;


/*----------------------------------------------------------------------
|   AP4_ByteStream implementation
+---------------------------------------------------------------------*/
void 
AP4_ByteStream_AddReference(AP4_ByteStream* self)
{
    self->AddReference();
}

void 
AP4_ByteStream_Release(AP4_ByteStream* self)
{
    self->Release();
}

AP4_Result 
AP4_ByteStream_ReadPartial(AP4_ByteStream*  self,
                           void*            buffer,
                           AP4_Size         bytes_to_read,
                           AP4_Size*        bytes_read)
{
    return self->ReadPartial(buffer, bytes_to_read, *bytes_read);
}

AP4_Result 
AP4_ByteStream_Read(AP4_ByteStream* self, 
                    void*           buffer, 
                    AP4_Size        bytes_to_read)
{
    return self->Read(buffer, bytes_to_read);
}

AP4_Result 
AP4_ByteStream_ReadDouble(AP4_ByteStream* self, double* value)
{
    return self->ReadDouble(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI64(AP4_ByteStream* self, AP4_UI64* value)
{
    return self->ReadUI64(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI32(AP4_ByteStream* self, AP4_UI32* value)
{
    return self->ReadUI32(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI24(AP4_ByteStream* self, AP4_UI32* value)
{
    return self->ReadUI24(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI16(AP4_ByteStream* self, AP4_UI16* value)
{
    return self->ReadUI16(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI08(AP4_ByteStream* self, AP4_UI08* value)
{
    return self->ReadUI08(*value);
}

AP4_Result 
AP4_ByteStream_ReadString(AP4_ByteStream* self, 
                          char*           buffer, 
                          AP4_Size        size)
{
    return self->ReadString(buffer, size);
}

AP4_Result 
AP4_ByteStream_WritePartial(AP4_ByteStream* self,
                            const void*     buffer,
                            AP4_Size        bytes_to_write,
                            AP4_Size*       bytes_written)
{
    return self->WritePartial(buffer, bytes_to_write, *bytes_written);
}

AP4_Result
AP4_ByteStream_Write(AP4_ByteStream* self,
                     const void*     buffer,
                     AP4_Size        bytes_to_write)
{
    return self->Write(buffer, bytes_to_write);
}

AP4_Result 
AP4_ByteStream_WriteDouble(AP4_ByteStream* self, double value)
{
    return self->WriteDouble(value);
}

AP4_Result 
AP4_ByteStream_WriteUI64(AP4_ByteStream* self, AP4_UI64 value)
{
    return self->WriteUI64(value);
}

AP4_Result 
AP4_ByteStream_WriteUI32(AP4_ByteStream* self, AP4_UI32 value)
{
    return self->WriteUI32(value);
}

AP4_Result 
AP4_ByteStream_WriteUI24(AP4_ByteStream* self, AP4_UI32 value)
{
    return self->WriteUI24(value);
}

AP4_Result 
AP4_ByteStream_WriteUI16(AP4_ByteStream* self, AP4_UI16 value)
{
    return self->WriteUI16(value);
}

AP4_Result 
AP4_ByteStream_WriteUI08(AP4_ByteStream* self, AP4_UI08 value)
{
    return self->WriteUI08(value);
}

AP4_Result 
AP4_ByteStream_WriteString(AP4_ByteStream* self, const char* buffer)
{
    return self->WriteString(buffer);
}

AP4_Result 
AP4_ByteStream_Seek(AP4_ByteStream* self, AP4_Position position)
{
    return self->Seek(position);
}

AP4_Result 
AP4_ByteStream_Tell(AP4_ByteStream* self, AP4_Position* position)
{
    return self->Tell(*position);
}

AP4_Result
AP4_ByteStream_GetSize(AP4_ByteStream* self, AP4_LargeSize* size)
{
    return self->GetSize(*size);
}

AP4_Result 
AP4_ByteStream_CopyTo(AP4_ByteStream* self, 
                      AP4_ByteStream* receiver, 
                      AP4_LargeSize   size)
{
    return self->CopyTo(*receiver, size);
}

AP4_Result 
Ap4_ByteStream_Flush(AP4_ByteStream* self)
{
    return self->Flush();
}

AP4_ByteStream* 
AP4_SubStream_Create(AP4_ByteStream* container, 
                     AP4_Position     position, 
                     AP4_LargeSize    size)
{
    return new AP4_SubStream(*container, position, size);
}

AP4_ByteStream* 
AP4_MemoryByteStream_Create(AP4_Size size)
{
    return new AP4_MemoryByteStream(size);
}

AP4_ByteStream* 
AP4_MemoryByteStream_FromBuffer(const AP4_UI08* buffer, AP4_Size size)
{
    return new AP4_MemoryByteStream(buffer, size);
}

AP4_ByteStream*
AP4_MemoryByteStream_AdaptDataBuffer(AP4_DataBuffer* buffer)
{
    return new AP4_MemoryByteStream(*buffer);
}

AP4_ByteStream*
AP4_FileByteStream_Create(const char* name, int mode, AP4_Result* result)
{
    AP4_Result      local_result;
    AP4_ByteStream* stream;
    
    local_result = AP4_FileByteStream::Create(name, (AP4_FileByteStream::Mode)mode, stream);
    if (result) *result = local_result;
    if (AP4_SUCCEEDED(result)) {
        return stream;
    } else {
        return NULL;
    }
}

/*----------------------------------------------------------------------
|   AP4_DataBuffer implementation
+---------------------------------------------------------------------*/
AP4_Result 
AP4_DataBuffer_SetBuffer(AP4_DataBuffer* self, AP4_Byte* buffer, AP4_Size size)
{
    return self->SetBuffer(buffer, size);
}

AP4_Result 
AP4_DataBuffer_SetBufferSize(AP4_DataBuffer* self, AP4_Size size)
{
    return self->SetBufferSize(size);
}

AP4_Size 
AP4_DataBuffer_GetBufferSize(const AP4_DataBuffer* self)
{
    return self->GetBufferSize();
}

const AP4_Byte*
AP4_DataBuffer_GetData(const AP4_DataBuffer* self)
{
    return self->GetData();
}

AP4_Byte*
AP4_DataBuffer_UseData(AP4_DataBuffer* self)
{
    return self->UseData();
}

AP4_Size
AP4_DataBuffer_GetDataSize(const AP4_DataBuffer* self)
{
    return self->GetDataSize();
}

AP4_Result
AP4_DataBuffer_SetDataSize(AP4_DataBuffer* self, AP4_Size size)
{
    return self->SetDataSize(size);
}

AP4_Result
AP4_DataBuffer_SetData(AP4_DataBuffer* self, 
                      const AP4_Byte*  data, 
                      AP4_Size         data_size)
{
    return self->SetData(data, data_size);
}
                      
AP4_Result
AP4_DataBuffer_Reserve(AP4_DataBuffer* self, AP4_Size size)
{
    return self->Reserve(size);
}

void 
AP4_DataBuffer_Destroy(AP4_DataBuffer* self) 
{
    delete self;
}

AP4_DataBuffer*
AP4_DataBuffer_Create(AP4_Size size)
{
    return new AP4_DataBuffer(size);
}

AP4_DataBuffer*
AP4_DataBuffer_FromData(const void* data, AP4_Size data_size)
{
    return new AP4_DataBuffer(data, data_size);
}

AP4_DataBuffer*
AP4_DataBuffer_Clone(const AP4_DataBuffer* other)
{
    return new AP4_DataBuffer(*other);
}

/*----------------------------------------------------------------------
|   AP4_File implementation
+---------------------------------------------------------------------*/
AP4_Movie*
AP4_File_GetMovie(AP4_File* self)
{
    return self->GetMovie();
}

/* TODO AP4_File_GetFileType */

AP4_Result 
AP4_File_SetFileType(AP4_File*    self,
                     AP4_UI32     major_brand,
                     AP4_UI32     minor_version,
                     AP4_UI32*    compatible_brands,
                     AP4_Cardinal compatible_brand_count)
{
    return self->SetFileType(major_brand, 
                             minor_version,
                             compatible_brands,
                             compatible_brand_count);
}
                     
int
AP4_File_IsMoovBeforeMdat(const AP4_File* self)
{
    return (int) self->IsMoovBeforeMdat();
}

/* TODO AP4_File_Inspect */

const AP4_MetaData*
AP4_File_GetMetaData(AP4_File* self)
{
    return self->GetMetaData();
}

void
AP4_File_Destroy(AP4_File* self) 
{
    delete self;
}

AP4_File*
AP4_File_Create(AP4_Movie* movie)
{
    return new AP4_File(movie);
}

AP4_File*
AP4_File_FromStream(AP4_ByteStream* stream, int moov_only)
{
    return new AP4_File(*stream, AP4_DefaultAtomFactory::Instance, moov_only); 
}

/*----------------------------------------------------------------------
|   AP4_Movie implementation
+---------------------------------------------------------------------*/
AP4_Cardinal
AP4_Movie_GetTrackCount(AP4_Movie* self)
{
    return self->GetTracks().ItemCount();
}

AP4_Track*
AP4_Movie_GetTrackByIndex(AP4_Movie* self, AP4_Ordinal index)
{
    AP4_Track* track = NULL;
    if (AP4_FAILED(self->GetTracks().Get(index, track))) {
        return NULL;
    } else {
        return track;
    }
}

AP4_Track*
AP4_Movie_GetTrackById(AP4_Movie* self, AP4_UI32 track_id)
{
    return self->GetTrack(track_id);
}

AP4_Track*
AP4_Movie_GetTrackByType(AP4_Movie* self, int type, AP4_Ordinal index)
{
    return self->GetTrack((AP4_Track::Type) type, index);
}

AP4_UI32
AP4_Movie_GetTimeScale(AP4_Movie* self)
{
    return self->GetTimeScale();
}

AP4_UI32
AP4_Movie_GetDuration(AP4_Movie* self)
{
    return self->GetDuration();
}

AP4_Duration
AP4_Movie_GetDurationMs(AP4_Movie* self)
{
    return self->GetDurationMs();
}

void
AP4_Movie_Destroy(AP4_Movie* self)
{
    delete self;
}

AP4_Movie*
AP4_Movie_Create(AP4_UI32 time_scale)
{
    return new AP4_Movie(time_scale);
}

/*----------------------------------------------------------------------
|   AP4_Track implementation
+---------------------------------------------------------------------*/
int
AP4_Track_GetType(AP4_Track* self)
{
    return self->GetType();
}

AP4_UI32
AP4_Track_GetHandlerType(AP4_Track* self)
{
    return self->GetHandlerType();
}

AP4_UI32
AP4_Track_GetDuration(AP4_Track* self)
{
    return self->GetDuration();
}

AP4_Duration
AP4_Track_GetDurationMs(AP4_Track* self)
{
    return self->GetDurationMs();
}

AP4_Cardinal
AP4_Track_GetSampleCount(AP4_Track* self)
{
    return self->GetSampleCount();
}

AP4_Result
AP4_Track_GetSample(AP4_Track* self, AP4_Ordinal index, AP4_Sample* sample)
{
    return self->GetSample(index, *sample);
}

AP4_Result
AP4_Track_ReadSample(AP4_Track*      self, 
                     AP4_Ordinal     index, 
                     AP4_Sample*     sample,
                     AP4_DataBuffer* data)
{
    return self->ReadSample(index, *sample, *data);
}

AP4_Result
AP4_Track_GetSampleIndexForTimeStampMs(AP4_Track*    self,
                                       AP4_TimeStamp ts,
                                       AP4_Ordinal*  index)
{
    return self->GetSampleIndexForTimeStampMs(ts, *index);
}
                                       
AP4_SampleDescription*
AP4_Track_GetSampleDescription(AP4_Track* self, AP4_Ordinal index)
{
    return self->GetSampleDescription(index);
}

AP4_UI32
AP4_Track_GetId(AP4_Track* self)
{
    return self->GetId();
}

AP4_Result
AP4_Track_SetId(AP4_Track* self, AP4_UI32 track_id)
{
    return self->SetId(track_id);
}

AP4_Result
AP4_Track_SetMovieTimeScale(AP4_Track* self, AP4_UI32 time_scale)
{
    return self->SetMovieTimeScale(time_scale);
}

AP4_UI32
AP4_Track_GetMediaTimeScale(AP4_Track* self)
{
    return self->GetMediaTimeScale();
}

AP4_UI32
AP4_Track_GetMediaDuration(AP4_Track* self)
{
    return self->GetMediaDuration();
}

const char* 
AP4_Track_GetName(AP4_Track* self)
{
    return self->GetTrackName();
}

const char*
AP4_Track_GetLanguage(AP4_Track* self)
{
    return self->GetTrackLanguage();
}

void 
AP4_Track_Destroy(AP4_Track* self)
{
    delete self;
}

AP4_Track* 
AP4_Track_Create(int                       type,
                 AP4_SyntheticSampleTable* sample_table,
                 AP4_UI32                  track_id,
                 AP4_UI32                  movie_time_scale, /* 0 = use default */
                 AP4_UI32                  track_duration,   /* in the movie time scale */
                 AP4_UI32                  media_time_scale,
                 AP4_UI32                  media_duration,   /* in the media time scale */
                 const char*               language,
                 AP4_UI32                  width,
                 AP4_UI32                  height)
{
    return new AP4_Track((AP4_Track::Type) type,
                         sample_table,
                         track_id,
                         movie_time_scale,
                         track_duration,
                         media_time_scale,
                         media_duration,
                         language,
                         width,
                         height);
}

/*----------------------------------------------------------------------
|   AP4_SampleDescription implementation
+---------------------------------------------------------------------*/
int
AP4_SampleDescription_GetType(AP4_SampleDescription* self)
{
    return self->GetType();
}

AP4_UI32
AP4_SampleDescription_GetFormat(AP4_SampleDescription* self)
{
    return self->GetFormat();
}

AP4_AudioSampleDescription*
AP4_SampleDescription_AsAudio(AP4_SampleDescription* self)
{
    return dynamic_cast<AP4_AudioSampleDescription*> (self);
}

AP4_VideoSampleDescription*
AP4_SampleDescription_AsVideo(AP4_SampleDescription* self)
{
    return dynamic_cast<AP4_VideoSampleDescription*> (self);
}

AP4_AvcSampleDescription*
AP4_SampleDescription_AsAvc(AP4_SampleDescription* self)
{
    return dynamic_cast<AP4_AvcSampleDescription*> (self);
}

AP4_MpegSampleDescription*
AP4_SampleDescription_AsMpeg(AP4_SampleDescription* self)
{
    return dynamic_cast<AP4_MpegSampleDescription*> (self);
}

AP4_MpegAudioSampleDescription*
AP4_SampleDescription_AsMpegAudio(AP4_SampleDescription* self)
{
    return dynamic_cast<AP4_MpegAudioSampleDescription*> (self);
}

AP4_UI32
AP4_AudioSampleDescription_GetSampleRate(AP4_AudioSampleDescription* self)
{
    return self->GetSampleRate();
}

AP4_UI16
AP4_AudioSampleDescription_GetSampleSize(AP4_AudioSampleDescription* self)
{
    return self->GetSampleSize();
}

AP4_UI16
AP4_AudioSampleDescription_GetChannelCount(AP4_AudioSampleDescription* self)
{
    return self->GetChannelCount();
}

AP4_UI32
AP4_VideoSampleDescription_GetWidth(AP4_VideoSampleDescription* self)
{
    return self->GetWidth();
}


AP4_UI16
AP4_VideoSampleDescription_GetHeight(AP4_VideoSampleDescription* self)
{
    return self->GetHeight();
}

AP4_UI16
AP4_VideoSampleDescription_GetDepth(AP4_VideoSampleDescription* self)
{
    return self->GetDepth();
}

const char*
AP4_VideoSampleDescription_GetCompressorName(AP4_VideoSampleDescription* self)
{
    return self->GetCompressorName();
}

AP4_UI08
AP4_AvcSampleDescription_GetConfigurationVersion(AP4_AvcSampleDescription* self)
{
    return self->GetConfigurationVersion();
}

AP4_UI08
AP4_AvcSampleDescription_GetProfile(AP4_AvcSampleDescription* self)
{
    return self->GetProfile();
}

AP4_UI08
AP4_AvcSampleDescription_GetLevel(AP4_AvcSampleDescription* self)
{
    return self->GetLevel();
}

AP4_UI08
AP4_AvcSampleDescription_GetProfileCompatibility(AP4_AvcSampleDescription* self)
{
    return self->GetProfileCompatibility();
}

AP4_Cardinal
AP4_AvcSampleDescription_GetSequenceParameterCount(AP4_AvcSampleDescription* self)
{
    return self->GetSequenceParameters().ItemCount();
}

const AP4_DataBuffer*
AP4_AvcSampleDescription_GetSequenceParameter(AP4_AvcSampleDescription* self,
                                              AP4_Ordinal               index)
{
    AP4_Array<AP4_DataBuffer>& params = self->GetSequenceParameters();
    if (index >= params.ItemCount()) {
        return NULL;
    } else {
        return &params[index];
    }
}
                                              
AP4_Cardinal
AP4_AvcSampleDescription_GetPictureParameterCount(AP4_AvcSampleDescription* self)
{
    return self->GetPictureParameters().ItemCount();
}

const AP4_DataBuffer*
AP4_AvcSampleDescription_GetPictureParameter(AP4_AvcSampleDescription* self,
                                             AP4_Ordinal               index)
{
    AP4_Array<AP4_DataBuffer>& params = self->GetPictureParameters();
    if (index >= params.ItemCount()) {
        return NULL;
    } else {
        return &params[index];
    }
}    
                                          
const AP4_DataBuffer*
AP4_AvcSampleDescription_GetRawBytes(AP4_AvcSampleDescription* self)
{
    return &self->GetRawBytes();
}

const char* 
AP4_AvcSampleDescription_GetProfileName(AP4_UI08 profile)
{
    return AP4_AvcSampleDescription::GetProfileName(profile);
}

AP4_UI08
AP4_MpegSampleDescription_GetStreamType(AP4_MpegSampleDescription* self)
{
    return self->GetStreamType();
}

AP4_UI08
AP4_MpegSampleDescription_GetObjectTypeId(AP4_MpegSampleDescription* self)
{
    return self->GetObjectTypeId();
}

AP4_UI32
AP4_MpegSampleDescription_GetBufferSize(AP4_MpegSampleDescription* self)
{
    return self->GetBufferSize();
}

AP4_UI32
AP4_MpegSampleDescription_GetMaxBitrate(AP4_MpegSampleDescription* self)
{
    return self->GetMaxBitrate();
}

AP4_UI32
AP4_MpegSampleDescription_GetAvgBitrate(AP4_MpegSampleDescription* self)
{
    return self->GetAvgBitrate();
}

const AP4_DataBuffer*
AP4_MpegSampleDescription_GetDecoderInfo(AP4_MpegSampleDescription* self)
{
    return &self->GetDecoderInfo();
}

AP4_UI08
AP4_MpegAudioSampleDescription_GetMpeg4AudioObjectType(AP4_MpegAudioSampleDescription* self)
{
    return self->GetMpeg4AudioObjectType();
}

const char*
AP4_MpegAudioSampleDescription_GetMpegAudioObjectTypeString(AP4_UI08 type)
{
    return AP4_MpegAudioSampleDescription::GetMpeg4AudioObjectTypeString(type);
}

void
AP4_SampleDescription_Destroy(AP4_SampleDescription* self)
{
    delete self;
}

AP4_SampleDescription*
AP4_MpegVideoSampleDescription_Create(AP4_UI08        oti,
                                      AP4_UI16        width,
                                      AP4_UI16        height,
                                      AP4_UI16        depth,
                                      const char*     compressor_name,
                                      const AP4_Byte* decoder_info,
                                      AP4_Size        decoder_info_size,
                                      AP4_UI32        buffer_size,
                                      AP4_UI32        max_bitrate,
                                      AP4_UI32        avg_bitrate)
{
    AP4_DataBuffer info(decoder_info, decoder_info_size);
    return new AP4_MpegVideoSampleDescription(oti,
                                              width,
                                              height,
                                              depth,
                                              compressor_name,
                                              &info,
                                              buffer_size,
                                              max_bitrate,
                                              avg_bitrate);
}

AP4_SampleDescription*
AP4_MpegAudioSampleDescription_Create(AP4_UI08        oti,
                                      AP4_UI32        sample_rate,
                                      AP4_UI32        sample_size,
                                      AP4_UI32        channel_count,
                                      const AP4_Byte* decoder_info,
                                      AP4_Size        decoder_info_size,
                                      AP4_UI32        buffer_size,
                                      AP4_UI32        max_bitrate,
                                      AP4_UI32        avg_bitrate)
{
    AP4_DataBuffer info(decoder_info, decoder_info_size);
    return new AP4_MpegAudioSampleDescription(oti,
                                              sample_rate,
                                              sample_size,
                                              channel_count,
                                              &info,
                                              buffer_size,
                                              max_bitrate,
                                              avg_bitrate);
}
                                      
AP4_SampleDescription*
AP4_MpegSystemSampleDescription_Create(AP4_UI08        stream_type,
                                       AP4_UI08        oti,
                                       const AP4_Byte* decoder_info,
                                       AP4_Size        decoder_info_size,
                                       AP4_UI32        buffer_size,
                                       AP4_UI32        max_bitrate,
                                       AP4_UI32        avg_bitrate)
{
    AP4_DataBuffer info(decoder_info, decoder_info_size);
    return new AP4_MpegSystemSampleDescription(stream_type,
                                               oti,
                                               &info,
                                               buffer_size,
                                               max_bitrate,
                                               avg_bitrate);
}
                                       
AP4_SampleDescription*
AP4_AvcSampleDescription_Create(AP4_UI16         width,
                                AP4_UI16         height,
                                AP4_UI16         depth,
                                const char*      compressor_name,
                                AP4_UI08         config_version,
                                AP4_UI08         profile,
                                AP4_UI08         level,
                                AP4_UI08         profile_compatibility,
                                AP4_UI08         nalu_length_size,
                                AP4_DataBuffer** sequence_parameters,
                                AP4_Size         sequence_parameter_count,
                                AP4_DataBuffer** picture_parameters,
                                AP4_Size         picture_parameter_count)
{
    AP4_Array<AP4_DataBuffer> sequence_params;
    AP4_Array<AP4_DataBuffer> picture_params;
    AP4_Ordinal i;
    
    for (i=0; i<sequence_parameter_count; i++) {
        sequence_params.Append(*sequence_parameters[i]);
    }
    for (i=0; i<picture_parameter_count; i++) {
        picture_params.Append(*picture_parameters[i]);
    }
    
    return new AP4_AvcSampleDescription(width,
                                        height,
                                        depth,
                                        compressor_name,
                                        config_version,
                                        profile,
                                        level,
                                        profile_compatibility,
                                        nalu_length_size,
                                        sequence_params,
                                        picture_params);
}

/*----------------------------------------------------------------------
|   AP4_Sample implementation
+---------------------------------------------------------------------*/
AP4_Result
AP4_Sample_ReadData(AP4_Sample* self, AP4_DataBuffer* data)
{
    return self->ReadData(*data);
}

AP4_Result
AP4_Sample_ReadPartialData(AP4_Sample*     self, 
                           AP4_DataBuffer* data,
                           AP4_Size        size,
                           AP4_Size        offset)
{
    return self->ReadData(*data, size, offset);
}

AP4_ByteStream*
AP4_Sample_GetDataStream(AP4_Sample* self)
{
    return self->GetDataStream();
}

void
AP4_Sample_SetDataStream(AP4_Sample* self, AP4_ByteStream* stream)
{
    self->SetDataStream(*stream);
}

AP4_Position
AP4_Sample_GetOffset(AP4_Sample* self)
{
    return self->GetOffset();
}

void
AP4_Sample_SetOffset(AP4_Sample* self, AP4_Position offset)
{
    self->SetOffset(offset);
}

AP4_Size
AP4_Sample_GetSize(AP4_Sample* self)
{
    return self->GetSize();
}

void
AP4_Sample_SetSize(AP4_Sample* self, AP4_Size size)
{
    self->SetSize(size);
}

AP4_Ordinal
AP4_Sample_GetDescriptionIndex(AP4_Sample* self)
{
    return self->GetDescriptionIndex();
}

void
AP4_Sample_SetDescriptionIndex(AP4_Sample* self, AP4_Ordinal index)
{
    self->SetDescriptionIndex(index);
}

AP4_UI32
AP4_Sample_GetDts(AP4_Sample* self)
{
    return self->GetDts();
}

void
AP4_SampleSetDts(AP4_Sample* self, AP4_UI32 dts)
{
    self->SetDts(dts);
}

AP4_UI32
AP4_Sample_GetCts(AP4_Sample* self)
{
    return self->GetCts();
}

void
AP4_Sample_SetCts(AP4_Sample* self, AP4_UI32 cts)
{
    self->SetCts(cts);
}

int
AP4_Sample_IsSync(AP4_Sample* self)
{
    return self->IsSync();
}

void
AP4_Sample_SetSync(AP4_Sample* self, int is_sync)
{
    self->SetSync(is_sync);
}

void 
AP4_Sample_Destroy(AP4_Sample* self)
{
    delete self;
}

AP4_Sample*
AP4_Sample_CreateEmpty(void)
{
    return new AP4_Sample();
}

AP4_Sample*
AP4_Sample_Create(AP4_ByteStream* data_stream,
                  AP4_Position    offset,
                  AP4_Size        size,
                  AP4_Ordinal     description_index,
                  AP4_TimeStamp   dts,
                  AP4_UI32        cts_offset,
                  int             is_sync)
{
    return new AP4_Sample(*data_stream,
                          offset,
                          size,
                          description_index,
                          dts,
                          cts_offset,
                          is_sync);
}
                  
AP4_Sample*
AP4_Sample_Clone(const AP4_Sample* other)
{
    return new AP4_Sample(*other);
}

/*----------------------------------------------------------------------
|   AP4_SyntheticSampleTable implementation
+---------------------------------------------------------------------*/
AP4_Result
AP4_SyntheticSampleTable_AddSampleDescription(AP4_SyntheticSampleTable* self,
                                              AP4_SampleDescription*    desc)
{
    return self->AddSampleDescription(desc);
}
                                              
AP4_Result
AP4_SyntheticSampleTable_AddSample(AP4_SyntheticSampleTable* self,
                                   AP4_ByteStream*           data_stream,
                                   AP4_Position              offset,
                                   AP4_Size                  size,
                                   AP4_Ordinal               desc_index,
                                   AP4_TimeStamp             cts, 
                                   AP4_TimeStamp             dts,
                                   int                       is_sync)
{
    return self->AddSample(*data_stream,
                           offset,
                           size,
                           desc_index,
                           cts,
                           dts,
                           is_sync);
}
                                   
/*----------------------------------------------------------------------
|   AP4_SyntheticSampleTable constructors
+---------------------------------------------------------------------*/
AP4_SyntheticSampleTable*
AP4_SyntheticSampleTable_Create(AP4_Cardinal chunk_size)
{
    return new AP4_SyntheticSampleTable(chunk_size);
}
