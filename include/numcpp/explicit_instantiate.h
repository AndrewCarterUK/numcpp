#ifndef NUMCPP_EXPLICIT_INSTANTIATE_H
#define NUMCPP_EXPLICIT_INSTANTIATE_H

#define NUMCPP_EXPLICIT_INSTANTIATE_CLASS(C) \
    template class C<char>; \
    template class C<unsigned char>; \
    template class C<short>; \
    template class C<unsigned short>; \
    template class C<int>; \
    template class C<unsigned int>; \
    template class C<long>; \
    template class C<unsigned long>; \
    template class C<long long>; \
    template class C<unsigned long long>; \
    template class C<float>; \
    template class C<double>; \
    template class C<long double>;

#endif
