// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file RTPSParticipantListener.h
 *
 */

#ifndef _FASTDDS_RTPS_PARTICIPANT_RTPSPARTICIPANTLISTENER_H__
#define _FASTDDS_RTPS_PARTICIPANT_RTPSPARTICIPANTLISTENER_H__

#include <fastdds/rtps/participant/ParticipantDiscoveryInfo.h>
#include <fastdds/rtps/reader/ReaderDiscoveryInfo.h>
#include <fastdds/rtps/writer/WriterDiscoveryInfo.h>

#include <fastrtps/types/DynamicTypePtr.h>
#include <fastrtps/types/TypeIdentifier.h>
#include <fastrtps/types/TypeObject.h>

namespace eprosima {
namespace fastrtps {
namespace rtps {

class RTPSParticipant;

/**
 * Class RTPSParticipantListener with virtual method that the user can overload to respond to certain events.
 * @ingroup RTPS_MODULE
 */
class RTPS_DllAPI RTPSParticipantListener
{
public:

    RTPSParticipantListener()
    {
    }

    virtual ~RTPSParticipantListener()
    {
    }

    /*!
     * This method is called when a new Participant is discovered, or a previously discovered participant changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote participant.
     * @param[out] info Remote participant information. User can take ownership of the object.
     */
    virtual void onParticipantDiscovery(
            RTPSParticipant* participant,
            ParticipantDiscoveryInfo&& info)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
    }

    /*!
     * This method is called when a new Participant is discovered, or a previously discovered participant changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote participant.
     * @param[out] info Remote participant information. User can take ownership of the object.
     * @param[out] should_be_ignored Flag to indicate the library to automatically ignore the discovered Participant.
     */
    virtual void onParticipantDiscovery(
            RTPSParticipant* participant,
            ParticipantDiscoveryInfo&& info,
            bool& should_be_ignored)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
        static_cast<void>(should_be_ignored);
    }

#if HAVE_SECURITY
    virtual void onParticipantAuthentication(
            RTPSParticipant* participant,
            ParticipantAuthenticationInfo&& info)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
    }

#endif // if HAVE_SECURITY

    /*!
     * This method is called when a new Reader is discovered, or a previously discovered reader changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote reader.
     * @param[out] info Remote reader information. User can take ownership of the object.
     */
    virtual void onReaderDiscovery(
            RTPSParticipant* participant,
            ReaderDiscoveryInfo&& info)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
    }

    /*!
     * This method is called when a new Reader is discovered, or a previously discovered reader changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote reader.
     * @param[out] info Remote reader information. User can take ownership of the object.
     * @param[out] should_be_ignored Flag to indicate the library to automatically ignore the discovered Reader.
     */
    virtual void onReaderDiscovery(
            RTPSParticipant* participant,
            ReaderDiscoveryInfo&& info,
            bool& should_be_ignored)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
        static_cast<void>(should_be_ignored);
    }

    /*!
     * This method is called when a new Writer is discovered, or a previously discovered writer changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote writer.
     * @param[out] info Remote writer information. User can take ownership of the object.
     */
    virtual void onWriterDiscovery(
            RTPSParticipant* participant,
            WriterDiscoveryInfo&& info)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
    }

    /*!
     * This method is called when a new Writer is discovered, or a previously discovered writer changes
     * its QOS or is removed.
     *
     * @param[out] participant Pointer to the Participant which discovered the remote writer.
     * @param[out] info Remote writer information. User can take ownership of the object.
     * @param[out] should_be_ignored Flag to indicate the library to automatically ignore the discovered Writer.
     */
    virtual void onWriterDiscovery(
            RTPSParticipant* participant,
            WriterDiscoveryInfo&& info,
            bool& should_be_ignored)
    {
        static_cast<void>(participant);
        static_cast<void>(info);
        static_cast<void>(should_be_ignored);
    }

    /*!
     * This method is called when a participant discovers a new Type
     * The ownership of all object belongs to the caller so if needs to be used after the
     * method ends, a full copy should be perform (except for dyn_type due to its shared_ptr nature.
     * The field "topic" it is only available if the type was discovered using "Discovery-Time Data Typing",
     * in which case the field request_sample_id will contain INVALID_SAMPLE_IDENTITY.
     * If the type was discovered using TypeLookup Service then "topic" will be empty, but will have
     * the request_sample_id of the petition that caused the discovery.
     * For example:
     * fastrtps::types::TypeIdentifier new_type_id = *identifier;
     */
    virtual void on_type_discovery(
            RTPSParticipant* participant,
            const SampleIdentity& request_sample_id,
            const string_255& topic,
            const types::TypeIdentifier* identifier,
            const types::TypeObject* object,
            types::DynamicType_ptr dyn_type)
    {
        static_cast<void>(participant);
        static_cast<void>(request_sample_id);
        static_cast<void>(topic);
        static_cast<void>(identifier);
        static_cast<void>(object);
        static_cast<void>(dyn_type);
    }

    /*!
     * This method is called when the typelookup client received a reply to a getTypeDependencies request.
     * The user may want to retrieve these new types using the getTypes request and create a new
     * DynamicType using the retrieved TypeObject.
     */
    virtual void on_type_dependencies_reply(
            RTPSParticipant* participant,
            const SampleIdentity& request_sample_id,
            const types::TypeIdentifierWithSizeSeq& dependencies)
    {
        static_cast<void>(participant);
        static_cast<void>(request_sample_id);
        static_cast<void>(dependencies);
    }

    /*!
     * This method is called when a participant receives a TypeInformation while discovering another participant.
     */
    virtual void on_type_information_received(
            RTPSParticipant* participant,
            const string_255& topic_name,
            const string_255& type_name,
            const types::TypeInformation& type_information)
    {
        static_cast<void>(participant);
        static_cast<void>(topic_name);
        static_cast<void>(type_name);
        static_cast<void>(type_information);
    }

};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif //_FASTDDS_RTPS_PARTICIPANT_RTPSPARTICIPANTLISTENER_H__
