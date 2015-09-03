/*******************************************************************************
 * Default implementations for non-standard abstract opperations
 *
 * We separate domain_traits.hpp from domain_traits_impl.hpp so that
 * we do not create cyclic dependencies when including headers. In
 * this way, abstract domains can also call domain_traits operations.
 *
 ******************************************************************************/


#ifndef DOMAINS_TRAITS_IMPL_HPP
#define DOMAINS_TRAITS_IMPL_HPP

#include <crab/domains/domain_traits.hpp>

namespace crab {

   namespace domain_traits {

        template <typename AbsNumDomain >
        void normalize(AbsNumDomain& inv) {
        }
     
        template <typename AbsNumDomain, typename Iterator >
        void forget(AbsNumDomain& inv, Iterator it, Iterator end){
          for (auto v : boost::make_iterator_range (it,end)){
            inv -= v; 
          }
        }
     
        template <typename AbsDomain, typename VariableName >
        void expand (AbsDomain& inv, VariableName x, VariableName new_x) {
          // make a new copy of x but losing precision if relational domain
          inv.set (new_x , inv [x]);
        }
     
        template <typename AbsDomain, typename VariableName>
        void array_init (AbsDomain& inv, VariableName a,
                         const vector<ikos::z_number>& vals) {
        }
     
        template <typename AbsDomain, typename VariableName, typename Number>
        void assume_array (AbsDomain& inv, VariableName a, Number val) {
        }

        template <typename AbsDomain, typename VariableName, typename Number>
        void assume_array (AbsDomain& inv, VariableName a, interval<Number> val) {
        }
     
        template <typename AbsDomain, typename VariableName >
        void array_load (AbsDomain& inv, VariableName lhs, 
                         VariableName a, VariableName i,
                         ikos::z_number n_bytes) {
        }

        template <typename AbsDomain, typename VariableName >
        void array_store (AbsDomain& inv, VariableName a, 
                          VariableName i, typename AbsDomain::linear_expression_t v,
                          ikos::z_number n_bytes, bool is_singleton) {
        }
     
   } //end namespace domain_traits
}// end crab
#endif 