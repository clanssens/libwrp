#ifndef LIBINT_EIGEN_INTEGRALS_HPP
#define LIBINT_EIGEN_INTEGRALS_HPP

#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>

#include <libint2.hpp>


namespace Wrapper {

/**
 * Given an operator type, an orbital basis and atoms, calculates the one-body integrals (associated to that operator type)

 * @param opertype: a libint2::Operator (e.g. libint2::Operator::overlap)
 * @param obs:      a libint2::BasisSet object that represents the basis put on the molecule
 * @param atoms:    a std::vector<Atom>

 * @return: an Eigen::MatrixXd storing the integrals
 */
Eigen::MatrixXd
compute_1body_integrals(const libint2::Operator &, const libint2::BasisSet &, const std::vector<libint2::Atom> &);

/**
 * Calculates the two-electron integrals, given an orbital basis and atoms.
 * The integrals are stored in a rank-4 tensor, which should be accessed using PHYSICIST'S NOTATION <12|12>.

 * @param obs:      a libint2::BasisSet object that represents the basis put on the molecule
 * @param atoms:    a std::vector<Atom>

 * @return: an Eigen::Tensor<double, 4> storing the integrals
 */
Eigen::Tensor<double, 4> compute_2body_integrals(const libint2::BasisSet &, const std::vector<libint2::Atom> &);

/**
 * Prints the sizes (i.e. the number of basis functions in them) of all shells in a given basis set object.
 */
void print_shell_sizes(const libint2::BasisSet &);

} // namespace Wrapper

#endif // LIBINT_EIGEN_INTEGRALS_HPP
