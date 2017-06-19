#ifndef FLIT_H
#define FLIT_H

#include <systemc.h>

#include "noccommon.h"

/*!
 * \brief The Flit class is responsible to represent the data inside of a Flit.
 * It has the data used by the NoC's Routers also data used only user Debug.
 */
class Flit
{
    /*!
     * \brief A global counter to the number of flits in the system.
     */
    static uint64_t _globalFlitCounter;

    /*!
     * \brief A unique identification number to this flit globally.
     */
    const uint64_t _globalId;

    /*!
     * \brief The data used by the NoC.
     */
    flit_t _data;

    /*!
     * \brief The identification number for this flit in the packet.
     */
    uint64_t _packetId;

public:
    /*!
     * \brief The default constructor.
     * \param data The flit data.
     * \param packetId The flit number inside of the packet.
     */
    Flit(flit_t data, uint64_t packetId);

    /*!
     * \brief Getter to the flit data.
     * \return The flit data.
     */
    flit_t getData();

    /*!
     * \brief Setter to the flit data.
     * \param data The new flit data.
     */
    void setData(flit_t data);

    /*!
     * \brief Getter to the system identification unique number to this flit.
     * \return The flit unique identification.
     */
    uint64_t getUniqueId();

    /*!
     * \brief Getter to the packet identification to this flit.
     * \return The flit packet identification.
     */
    uint64_t getPacketId();
};

#endif // FLIT_H