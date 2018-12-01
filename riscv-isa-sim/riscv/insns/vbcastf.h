require_extension('V');
require_rv64;
vreg_t vect;
vect.e32[0] = f32(FRS1).v;
WRITE_VRD(v_bcast(vect, EW, VL));
