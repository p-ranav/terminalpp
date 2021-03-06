#pragma once

#include "terminalpp/core.hpp"
#include <iosfwd>

namespace terminalpp {

//* =========================================================================
/// \brief A class that represents a direction with distance in space
/// (a vector).
/// \par
/// A class that represents a direction in space, with width being the
/// extent in the horizontal axis, and height being the extent in the
/// vertical axis.
//* =========================================================================
struct extent
{
    //* =====================================================================
    /// \brief Default Constructor
    /// \par
    /// Constructs an extent, leaving the width and height zeroed.
    //* =====================================================================
    constexpr extent()
      : width(0),
        height(0)
    {
    }

    //* =====================================================================
    /// \brief Constructor
    /// \par
    /// Constructs an extent with width and height being set to the passed-in
    /// arguments.
    //* =====================================================================
    constexpr extent(coordinate_type w, coordinate_type h)
      : width(w),
        height(h)
    {
    }

    //* =====================================================================
    /// \brief Addition
    //* =====================================================================
    constexpr extent &operator+=(extent const &rhs)
    {
        width  += rhs.width;
        height += rhs.height;
        return *this;
    }

    //* =====================================================================
    /// \brief Subtraction
    //* =====================================================================
    constexpr extent &operator-=(extent const &rhs)
    {
        width  -= rhs.width;
        height -= rhs.height;
        return *this;
    }

    coordinate_type width;
    coordinate_type height;
};

// ==========================================================================
// OPERATOR==(EXTENT,EXTENT)
// ==========================================================================
constexpr bool operator==(extent const &lhs, extent const &rhs)
{
    return lhs.width == rhs.width && lhs.height == rhs.height;
}

// ==========================================================================
// OPERATOR!=(EXTENT,EXTENT)
// ==========================================================================
constexpr bool operator!=(extent const &lhs, extent const &rhs)
{
    return !(lhs == rhs);
}

// ==========================================================================
// OPERATOR+(EXTENT,EXTENT)
// ==========================================================================
constexpr extent operator+(extent lhs, extent const &rhs)
{
    return lhs += rhs;
}

// ==========================================================================
// OPERATOR-(EXTENT,EXTENT)
// ==========================================================================
constexpr extent operator-(extent lhs, extent const &rhs)
{
    return lhs -= rhs;
}

//* =====================================================================
/// \brief Outputs the current state of the extent to a stream.
/// For example, "extent(35,49)"
//* =====================================================================
TERMINALPP_EXPORT
std::ostream &operator<<(std::ostream &out, extent const &ext);

}
