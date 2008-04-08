# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _ml
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


class CvRNG_Wrapper(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvRNG_Wrapper, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvRNG_Wrapper, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvRNG_Wrapper(*args)
        try: self.this.append(this)
        except: self.this = this
    def ptr(*args): return _ml.CvRNG_Wrapper_ptr(*args)
    def ref(*args): return _ml.CvRNG_Wrapper_ref(*args)
    def __eq__(*args): return _ml.CvRNG_Wrapper___eq__(*args)
    def __ne__(*args): return _ml.CvRNG_Wrapper___ne__(*args)
    __swig_destroy__ = _ml.delete_CvRNG_Wrapper
    __del__ = lambda self : None;
CvRNG_Wrapper_swigregister = _ml.CvRNG_Wrapper_swigregister
CvRNG_Wrapper_swigregister(CvRNG_Wrapper)

class CvSubdiv2DEdge_Wrapper(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSubdiv2DEdge_Wrapper, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSubdiv2DEdge_Wrapper, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvSubdiv2DEdge_Wrapper(*args)
        try: self.this.append(this)
        except: self.this = this
    def ptr(*args): return _ml.CvSubdiv2DEdge_Wrapper_ptr(*args)
    def ref(*args): return _ml.CvSubdiv2DEdge_Wrapper_ref(*args)
    def __eq__(*args): return _ml.CvSubdiv2DEdge_Wrapper___eq__(*args)
    def __ne__(*args): return _ml.CvSubdiv2DEdge_Wrapper___ne__(*args)
    __swig_destroy__ = _ml.delete_CvSubdiv2DEdge_Wrapper
    __del__ = lambda self : None;
CvSubdiv2DEdge_Wrapper_swigregister = _ml.CvSubdiv2DEdge_Wrapper_swigregister
CvSubdiv2DEdge_Wrapper_swigregister(CvSubdiv2DEdge_Wrapper)

import cv
__doc__ = """Machine Learning

The Machine Learning library (ML) is a set of classes and functions for 
statistical classification, regression and clustering of data.

Most of the classification and regression algorithms are implemented as classes. 
As the algorithms have different sets of features (like ability to handle missing 
measurements, or categorical input variables etc.), there is only little common 
ground between the classes. This common ground is defined by the class CvStatModel 
that all the other ML classes are derived from.

This wrapper was semi-automatically created from the C/C++ headers and therefore
contains no Python documentation. Because all identifiers are identical to their
C/C++ counterparts, you can consult the standard manuals that come with OpenCV.
"""


CV_LOG2PI = _ml.CV_LOG2PI
CV_COL_SAMPLE = _ml.CV_COL_SAMPLE
CV_ROW_SAMPLE = _ml.CV_ROW_SAMPLE
class CvVectors(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvVectors, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvVectors, name)
    __repr__ = _swig_repr
    __swig_setmethods__["type"] = _ml.CvVectors_type_set
    __swig_getmethods__["type"] = _ml.CvVectors_type_get
    if _newclass:type = property(_ml.CvVectors_type_get, _ml.CvVectors_type_set)
    __swig_setmethods__["dims"] = _ml.CvVectors_dims_set
    __swig_getmethods__["dims"] = _ml.CvVectors_dims_get
    if _newclass:dims = property(_ml.CvVectors_dims_get, _ml.CvVectors_dims_set)
    __swig_setmethods__["count"] = _ml.CvVectors_count_set
    __swig_getmethods__["count"] = _ml.CvVectors_count_get
    if _newclass:count = property(_ml.CvVectors_count_get, _ml.CvVectors_count_set)
    __swig_setmethods__["next"] = _ml.CvVectors_next_set
    __swig_getmethods__["next"] = _ml.CvVectors_next_get
    if _newclass:next = property(_ml.CvVectors_next_get, _ml.CvVectors_next_set)
    __swig_getmethods__["data"] = _ml.CvVectors_data_get
    if _newclass:data = property(_ml.CvVectors_data_get)
    def __init__(self, *args): 
        this = _ml.new_CvVectors(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvVectors
    __del__ = lambda self : None;
CvVectors_swigregister = _ml.CvVectors_swigregister
CvVectors_swigregister(CvVectors)

class CvVectors_data(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvVectors_data, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvVectors_data, name)
    __repr__ = _swig_repr
    __swig_setmethods__["ptr"] = _ml.CvVectors_data_ptr_set
    __swig_getmethods__["ptr"] = _ml.CvVectors_data_ptr_get
    if _newclass:ptr = property(_ml.CvVectors_data_ptr_get, _ml.CvVectors_data_ptr_set)
    __swig_setmethods__["fl"] = _ml.CvVectors_data_fl_set
    __swig_getmethods__["fl"] = _ml.CvVectors_data_fl_get
    if _newclass:fl = property(_ml.CvVectors_data_fl_get, _ml.CvVectors_data_fl_set)
    __swig_setmethods__["db"] = _ml.CvVectors_data_db_set
    __swig_getmethods__["db"] = _ml.CvVectors_data_db_get
    if _newclass:db = property(_ml.CvVectors_data_db_get, _ml.CvVectors_data_db_set)
    def __init__(self, *args): 
        this = _ml.new_CvVectors_data(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvVectors_data
    __del__ = lambda self : None;
CvVectors_data_swigregister = _ml.CvVectors_data_swigregister
CvVectors_data_swigregister(CvVectors_data)

CV_VAR_NUMERICAL = _ml.CV_VAR_NUMERICAL
CV_VAR_ORDERED = _ml.CV_VAR_ORDERED
CV_VAR_CATEGORICAL = _ml.CV_VAR_CATEGORICAL
CV_TYPE_NAME_ML_SVM = _ml.CV_TYPE_NAME_ML_SVM
CV_TYPE_NAME_ML_KNN = _ml.CV_TYPE_NAME_ML_KNN
CV_TYPE_NAME_ML_NBAYES = _ml.CV_TYPE_NAME_ML_NBAYES
CV_TYPE_NAME_ML_EM = _ml.CV_TYPE_NAME_ML_EM
CV_TYPE_NAME_ML_BOOSTING = _ml.CV_TYPE_NAME_ML_BOOSTING
CV_TYPE_NAME_ML_TREE = _ml.CV_TYPE_NAME_ML_TREE
CV_TYPE_NAME_ML_ANN_MLP = _ml.CV_TYPE_NAME_ML_ANN_MLP
CV_TYPE_NAME_ML_CNN = _ml.CV_TYPE_NAME_ML_CNN
CV_TYPE_NAME_ML_RTREES = _ml.CV_TYPE_NAME_ML_RTREES
class CvStatModel(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvStatModel, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvStatModel, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvStatModel(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvStatModel
    __del__ = lambda self : None;
    def clear(*args): return _ml.CvStatModel_clear(*args)
    def save(*args): return _ml.CvStatModel_save(*args)
    def load(*args): return _ml.CvStatModel_load(*args)
    def write(*args): return _ml.CvStatModel_write(*args)
    def read(*args): return _ml.CvStatModel_read(*args)
CvStatModel_swigregister = _ml.CvStatModel_swigregister
CvStatModel_swigregister(CvStatModel)

class CvParamGrid(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvParamGrid, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvParamGrid, name)
    __repr__ = _swig_repr
    SVM_C = _ml.CvParamGrid_SVM_C
    SVM_GAMMA = _ml.CvParamGrid_SVM_GAMMA
    SVM_P = _ml.CvParamGrid_SVM_P
    SVM_NU = _ml.CvParamGrid_SVM_NU
    SVM_COEF = _ml.CvParamGrid_SVM_COEF
    SVM_DEGREE = _ml.CvParamGrid_SVM_DEGREE
    def __init__(self, *args): 
        this = _ml.new_CvParamGrid(*args)
        try: self.this.append(this)
        except: self.this = this
    def check(*args): return _ml.CvParamGrid_check(*args)
    __swig_setmethods__["min_val"] = _ml.CvParamGrid_min_val_set
    __swig_getmethods__["min_val"] = _ml.CvParamGrid_min_val_get
    if _newclass:min_val = property(_ml.CvParamGrid_min_val_get, _ml.CvParamGrid_min_val_set)
    __swig_setmethods__["max_val"] = _ml.CvParamGrid_max_val_set
    __swig_getmethods__["max_val"] = _ml.CvParamGrid_max_val_get
    if _newclass:max_val = property(_ml.CvParamGrid_max_val_get, _ml.CvParamGrid_max_val_set)
    __swig_setmethods__["step"] = _ml.CvParamGrid_step_set
    __swig_getmethods__["step"] = _ml.CvParamGrid_step_get
    if _newclass:step = property(_ml.CvParamGrid_step_get, _ml.CvParamGrid_step_set)
    __swig_destroy__ = _ml.delete_CvParamGrid
    __del__ = lambda self : None;
CvParamGrid_swigregister = _ml.CvParamGrid_swigregister
CvParamGrid_swigregister(CvParamGrid)

class CvNormalBayesClassifier(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvNormalBayesClassifier, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvNormalBayesClassifier, name)
    __repr__ = _swig_repr
    __swig_destroy__ = _ml.delete_CvNormalBayesClassifier
    __del__ = lambda self : None;
    def __init__(self, *args): 
        this = _ml.new_CvNormalBayesClassifier(*args)
        try: self.this.append(this)
        except: self.this = this
    def train(*args): return _ml.CvNormalBayesClassifier_train(*args)
    def predict(*args): return _ml.CvNormalBayesClassifier_predict(*args)
    def clear(*args): return _ml.CvNormalBayesClassifier_clear(*args)
    def write(*args): return _ml.CvNormalBayesClassifier_write(*args)
    def read(*args): return _ml.CvNormalBayesClassifier_read(*args)
CvNormalBayesClassifier_swigregister = _ml.CvNormalBayesClassifier_swigregister
CvNormalBayesClassifier_swigregister(CvNormalBayesClassifier)

class CvKNearest(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvKNearest, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvKNearest, name)
    __repr__ = _swig_repr
    __swig_destroy__ = _ml.delete_CvKNearest
    __del__ = lambda self : None;
    def __init__(self, *args): 
        this = _ml.new_CvKNearest(*args)
        try: self.this.append(this)
        except: self.this = this
    def train(*args): return _ml.CvKNearest_train(*args)
    def find_nearest(*args): return _ml.CvKNearest_find_nearest(*args)
    def clear(*args): return _ml.CvKNearest_clear(*args)
    def get_max_k(*args): return _ml.CvKNearest_get_max_k(*args)
    def get_var_count(*args): return _ml.CvKNearest_get_var_count(*args)
    def get_sample_count(*args): return _ml.CvKNearest_get_sample_count(*args)
    def is_regression(*args): return _ml.CvKNearest_is_regression(*args)
CvKNearest_swigregister = _ml.CvKNearest_swigregister
CvKNearest_swigregister(CvKNearest)

class CvSVMParams(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMParams, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMParams, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvSVMParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_setmethods__["svm_type"] = _ml.CvSVMParams_svm_type_set
    __swig_getmethods__["svm_type"] = _ml.CvSVMParams_svm_type_get
    if _newclass:svm_type = property(_ml.CvSVMParams_svm_type_get, _ml.CvSVMParams_svm_type_set)
    __swig_setmethods__["kernel_type"] = _ml.CvSVMParams_kernel_type_set
    __swig_getmethods__["kernel_type"] = _ml.CvSVMParams_kernel_type_get
    if _newclass:kernel_type = property(_ml.CvSVMParams_kernel_type_get, _ml.CvSVMParams_kernel_type_set)
    __swig_setmethods__["degree"] = _ml.CvSVMParams_degree_set
    __swig_getmethods__["degree"] = _ml.CvSVMParams_degree_get
    if _newclass:degree = property(_ml.CvSVMParams_degree_get, _ml.CvSVMParams_degree_set)
    __swig_setmethods__["gamma"] = _ml.CvSVMParams_gamma_set
    __swig_getmethods__["gamma"] = _ml.CvSVMParams_gamma_get
    if _newclass:gamma = property(_ml.CvSVMParams_gamma_get, _ml.CvSVMParams_gamma_set)
    __swig_setmethods__["coef0"] = _ml.CvSVMParams_coef0_set
    __swig_getmethods__["coef0"] = _ml.CvSVMParams_coef0_get
    if _newclass:coef0 = property(_ml.CvSVMParams_coef0_get, _ml.CvSVMParams_coef0_set)
    __swig_setmethods__["C"] = _ml.CvSVMParams_C_set
    __swig_getmethods__["C"] = _ml.CvSVMParams_C_get
    if _newclass:C = property(_ml.CvSVMParams_C_get, _ml.CvSVMParams_C_set)
    __swig_setmethods__["nu"] = _ml.CvSVMParams_nu_set
    __swig_getmethods__["nu"] = _ml.CvSVMParams_nu_get
    if _newclass:nu = property(_ml.CvSVMParams_nu_get, _ml.CvSVMParams_nu_set)
    __swig_setmethods__["p"] = _ml.CvSVMParams_p_set
    __swig_getmethods__["p"] = _ml.CvSVMParams_p_get
    if _newclass:p = property(_ml.CvSVMParams_p_get, _ml.CvSVMParams_p_set)
    __swig_setmethods__["class_weights"] = _ml.CvSVMParams_class_weights_set
    __swig_getmethods__["class_weights"] = _ml.CvSVMParams_class_weights_get
    if _newclass:class_weights = property(_ml.CvSVMParams_class_weights_get, _ml.CvSVMParams_class_weights_set)
    __swig_setmethods__["term_crit"] = _ml.CvSVMParams_term_crit_set
    __swig_getmethods__["term_crit"] = _ml.CvSVMParams_term_crit_get
    if _newclass:term_crit = property(_ml.CvSVMParams_term_crit_get, _ml.CvSVMParams_term_crit_set)
    __swig_destroy__ = _ml.delete_CvSVMParams
    __del__ = lambda self : None;
CvSVMParams_swigregister = _ml.CvSVMParams_swigregister
CvSVMParams_swigregister(CvSVMParams)

class CvSVMKernel(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMKernel, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMKernel, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvSVMKernel(*args)
        try: self.this.append(this)
        except: self.this = this
    def create(*args): return _ml.CvSVMKernel_create(*args)
    __swig_destroy__ = _ml.delete_CvSVMKernel
    __del__ = lambda self : None;
    def clear(*args): return _ml.CvSVMKernel_clear(*args)
    def calc(*args): return _ml.CvSVMKernel_calc(*args)
    __swig_setmethods__["params"] = _ml.CvSVMKernel_params_set
    __swig_getmethods__["params"] = _ml.CvSVMKernel_params_get
    if _newclass:params = property(_ml.CvSVMKernel_params_get, _ml.CvSVMKernel_params_set)
    __swig_setmethods__["calc_func"] = _ml.CvSVMKernel_calc_func_set
    __swig_getmethods__["calc_func"] = _ml.CvSVMKernel_calc_func_get
    if _newclass:calc_func = property(_ml.CvSVMKernel_calc_func_get, _ml.CvSVMKernel_calc_func_set)
    def calc_non_rbf_base(*args): return _ml.CvSVMKernel_calc_non_rbf_base(*args)
    def calc_linear(*args): return _ml.CvSVMKernel_calc_linear(*args)
    def calc_rbf(*args): return _ml.CvSVMKernel_calc_rbf(*args)
    def calc_poly(*args): return _ml.CvSVMKernel_calc_poly(*args)
    def calc_sigmoid(*args): return _ml.CvSVMKernel_calc_sigmoid(*args)
CvSVMKernel_swigregister = _ml.CvSVMKernel_swigregister
CvSVMKernel_swigregister(CvSVMKernel)

class CvSVMKernelRow(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMKernelRow, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMKernelRow, name)
    __repr__ = _swig_repr
    __swig_setmethods__["prev"] = _ml.CvSVMKernelRow_prev_set
    __swig_getmethods__["prev"] = _ml.CvSVMKernelRow_prev_get
    if _newclass:prev = property(_ml.CvSVMKernelRow_prev_get, _ml.CvSVMKernelRow_prev_set)
    __swig_setmethods__["next"] = _ml.CvSVMKernelRow_next_set
    __swig_getmethods__["next"] = _ml.CvSVMKernelRow_next_get
    if _newclass:next = property(_ml.CvSVMKernelRow_next_get, _ml.CvSVMKernelRow_next_set)
    __swig_setmethods__["data"] = _ml.CvSVMKernelRow_data_set
    __swig_getmethods__["data"] = _ml.CvSVMKernelRow_data_get
    if _newclass:data = property(_ml.CvSVMKernelRow_data_get, _ml.CvSVMKernelRow_data_set)
    def __init__(self, *args): 
        this = _ml.new_CvSVMKernelRow(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvSVMKernelRow
    __del__ = lambda self : None;
CvSVMKernelRow_swigregister = _ml.CvSVMKernelRow_swigregister
CvSVMKernelRow_swigregister(CvSVMKernelRow)

class CvSVMSolutionInfo(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMSolutionInfo, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMSolutionInfo, name)
    __repr__ = _swig_repr
    __swig_setmethods__["obj"] = _ml.CvSVMSolutionInfo_obj_set
    __swig_getmethods__["obj"] = _ml.CvSVMSolutionInfo_obj_get
    if _newclass:obj = property(_ml.CvSVMSolutionInfo_obj_get, _ml.CvSVMSolutionInfo_obj_set)
    __swig_setmethods__["rho"] = _ml.CvSVMSolutionInfo_rho_set
    __swig_getmethods__["rho"] = _ml.CvSVMSolutionInfo_rho_get
    if _newclass:rho = property(_ml.CvSVMSolutionInfo_rho_get, _ml.CvSVMSolutionInfo_rho_set)
    __swig_setmethods__["upper_bound_p"] = _ml.CvSVMSolutionInfo_upper_bound_p_set
    __swig_getmethods__["upper_bound_p"] = _ml.CvSVMSolutionInfo_upper_bound_p_get
    if _newclass:upper_bound_p = property(_ml.CvSVMSolutionInfo_upper_bound_p_get, _ml.CvSVMSolutionInfo_upper_bound_p_set)
    __swig_setmethods__["upper_bound_n"] = _ml.CvSVMSolutionInfo_upper_bound_n_set
    __swig_getmethods__["upper_bound_n"] = _ml.CvSVMSolutionInfo_upper_bound_n_get
    if _newclass:upper_bound_n = property(_ml.CvSVMSolutionInfo_upper_bound_n_get, _ml.CvSVMSolutionInfo_upper_bound_n_set)
    __swig_setmethods__["r"] = _ml.CvSVMSolutionInfo_r_set
    __swig_getmethods__["r"] = _ml.CvSVMSolutionInfo_r_get
    if _newclass:r = property(_ml.CvSVMSolutionInfo_r_get, _ml.CvSVMSolutionInfo_r_set)
    def __init__(self, *args): 
        this = _ml.new_CvSVMSolutionInfo(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvSVMSolutionInfo
    __del__ = lambda self : None;
CvSVMSolutionInfo_swigregister = _ml.CvSVMSolutionInfo_swigregister
CvSVMSolutionInfo_swigregister(CvSVMSolutionInfo)

class CvSVMSolver(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMSolver, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMSolver, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvSVMSolver(*args)
        try: self.this.append(this)
        except: self.this = this
    def create(*args): return _ml.CvSVMSolver_create(*args)
    __swig_destroy__ = _ml.delete_CvSVMSolver
    __del__ = lambda self : None;
    def clear(*args): return _ml.CvSVMSolver_clear(*args)
    def solve_generic(*args): return _ml.CvSVMSolver_solve_generic(*args)
    def solve_c_svc(*args): return _ml.CvSVMSolver_solve_c_svc(*args)
    def solve_nu_svc(*args): return _ml.CvSVMSolver_solve_nu_svc(*args)
    def solve_one_class(*args): return _ml.CvSVMSolver_solve_one_class(*args)
    def solve_eps_svr(*args): return _ml.CvSVMSolver_solve_eps_svr(*args)
    def solve_nu_svr(*args): return _ml.CvSVMSolver_solve_nu_svr(*args)
    def get_row_base(*args): return _ml.CvSVMSolver_get_row_base(*args)
    def get_row(*args): return _ml.CvSVMSolver_get_row(*args)
    __swig_setmethods__["sample_count"] = _ml.CvSVMSolver_sample_count_set
    __swig_getmethods__["sample_count"] = _ml.CvSVMSolver_sample_count_get
    if _newclass:sample_count = property(_ml.CvSVMSolver_sample_count_get, _ml.CvSVMSolver_sample_count_set)
    __swig_setmethods__["var_count"] = _ml.CvSVMSolver_var_count_set
    __swig_getmethods__["var_count"] = _ml.CvSVMSolver_var_count_get
    if _newclass:var_count = property(_ml.CvSVMSolver_var_count_get, _ml.CvSVMSolver_var_count_set)
    __swig_setmethods__["cache_size"] = _ml.CvSVMSolver_cache_size_set
    __swig_getmethods__["cache_size"] = _ml.CvSVMSolver_cache_size_get
    if _newclass:cache_size = property(_ml.CvSVMSolver_cache_size_get, _ml.CvSVMSolver_cache_size_set)
    __swig_setmethods__["cache_line_size"] = _ml.CvSVMSolver_cache_line_size_set
    __swig_getmethods__["cache_line_size"] = _ml.CvSVMSolver_cache_line_size_get
    if _newclass:cache_line_size = property(_ml.CvSVMSolver_cache_line_size_get, _ml.CvSVMSolver_cache_line_size_set)
    __swig_setmethods__["samples"] = _ml.CvSVMSolver_samples_set
    __swig_getmethods__["samples"] = _ml.CvSVMSolver_samples_get
    if _newclass:samples = property(_ml.CvSVMSolver_samples_get, _ml.CvSVMSolver_samples_set)
    __swig_setmethods__["params"] = _ml.CvSVMSolver_params_set
    __swig_getmethods__["params"] = _ml.CvSVMSolver_params_get
    if _newclass:params = property(_ml.CvSVMSolver_params_get, _ml.CvSVMSolver_params_set)
    __swig_setmethods__["storage"] = _ml.CvSVMSolver_storage_set
    __swig_getmethods__["storage"] = _ml.CvSVMSolver_storage_get
    if _newclass:storage = property(_ml.CvSVMSolver_storage_get, _ml.CvSVMSolver_storage_set)
    __swig_setmethods__["lru_list"] = _ml.CvSVMSolver_lru_list_set
    __swig_getmethods__["lru_list"] = _ml.CvSVMSolver_lru_list_get
    if _newclass:lru_list = property(_ml.CvSVMSolver_lru_list_get, _ml.CvSVMSolver_lru_list_set)
    __swig_setmethods__["rows"] = _ml.CvSVMSolver_rows_set
    __swig_getmethods__["rows"] = _ml.CvSVMSolver_rows_get
    if _newclass:rows = property(_ml.CvSVMSolver_rows_get, _ml.CvSVMSolver_rows_set)
    __swig_setmethods__["alpha_count"] = _ml.CvSVMSolver_alpha_count_set
    __swig_getmethods__["alpha_count"] = _ml.CvSVMSolver_alpha_count_get
    if _newclass:alpha_count = property(_ml.CvSVMSolver_alpha_count_get, _ml.CvSVMSolver_alpha_count_set)
    __swig_setmethods__["G"] = _ml.CvSVMSolver_G_set
    __swig_getmethods__["G"] = _ml.CvSVMSolver_G_get
    if _newclass:G = property(_ml.CvSVMSolver_G_get, _ml.CvSVMSolver_G_set)
    __swig_setmethods__["alpha"] = _ml.CvSVMSolver_alpha_set
    __swig_getmethods__["alpha"] = _ml.CvSVMSolver_alpha_get
    if _newclass:alpha = property(_ml.CvSVMSolver_alpha_get, _ml.CvSVMSolver_alpha_set)
    __swig_setmethods__["alpha_status"] = _ml.CvSVMSolver_alpha_status_set
    __swig_getmethods__["alpha_status"] = _ml.CvSVMSolver_alpha_status_get
    if _newclass:alpha_status = property(_ml.CvSVMSolver_alpha_status_get, _ml.CvSVMSolver_alpha_status_set)
    __swig_setmethods__["y"] = _ml.CvSVMSolver_y_set
    __swig_getmethods__["y"] = _ml.CvSVMSolver_y_get
    if _newclass:y = property(_ml.CvSVMSolver_y_get, _ml.CvSVMSolver_y_set)
    __swig_setmethods__["b"] = _ml.CvSVMSolver_b_set
    __swig_getmethods__["b"] = _ml.CvSVMSolver_b_get
    if _newclass:b = property(_ml.CvSVMSolver_b_get, _ml.CvSVMSolver_b_set)
    __swig_setmethods__["buf"] = _ml.CvSVMSolver_buf_set
    __swig_getmethods__["buf"] = _ml.CvSVMSolver_buf_get
    if _newclass:buf = property(_ml.CvSVMSolver_buf_get, _ml.CvSVMSolver_buf_set)
    __swig_setmethods__["eps"] = _ml.CvSVMSolver_eps_set
    __swig_getmethods__["eps"] = _ml.CvSVMSolver_eps_get
    if _newclass:eps = property(_ml.CvSVMSolver_eps_get, _ml.CvSVMSolver_eps_set)
    __swig_setmethods__["max_iter"] = _ml.CvSVMSolver_max_iter_set
    __swig_getmethods__["max_iter"] = _ml.CvSVMSolver_max_iter_get
    if _newclass:max_iter = property(_ml.CvSVMSolver_max_iter_get, _ml.CvSVMSolver_max_iter_set)
    __swig_setmethods__["C"] = _ml.CvSVMSolver_C_set
    __swig_getmethods__["C"] = _ml.CvSVMSolver_C_get
    if _newclass:C = property(_ml.CvSVMSolver_C_get, _ml.CvSVMSolver_C_set)
    __swig_setmethods__["kernel"] = _ml.CvSVMSolver_kernel_set
    __swig_getmethods__["kernel"] = _ml.CvSVMSolver_kernel_get
    if _newclass:kernel = property(_ml.CvSVMSolver_kernel_get, _ml.CvSVMSolver_kernel_set)
    __swig_setmethods__["select_working_set_func"] = _ml.CvSVMSolver_select_working_set_func_set
    __swig_getmethods__["select_working_set_func"] = _ml.CvSVMSolver_select_working_set_func_get
    if _newclass:select_working_set_func = property(_ml.CvSVMSolver_select_working_set_func_get, _ml.CvSVMSolver_select_working_set_func_set)
    __swig_setmethods__["calc_rho_func"] = _ml.CvSVMSolver_calc_rho_func_set
    __swig_getmethods__["calc_rho_func"] = _ml.CvSVMSolver_calc_rho_func_get
    if _newclass:calc_rho_func = property(_ml.CvSVMSolver_calc_rho_func_get, _ml.CvSVMSolver_calc_rho_func_set)
    __swig_setmethods__["get_row_func"] = _ml.CvSVMSolver_get_row_func_set
    __swig_getmethods__["get_row_func"] = _ml.CvSVMSolver_get_row_func_get
    if _newclass:get_row_func = property(_ml.CvSVMSolver_get_row_func_get, _ml.CvSVMSolver_get_row_func_set)
    def select_working_set(*args): return _ml.CvSVMSolver_select_working_set(*args)
    def select_working_set_nu_svm(*args): return _ml.CvSVMSolver_select_working_set_nu_svm(*args)
    def calc_rho(*args): return _ml.CvSVMSolver_calc_rho(*args)
    def calc_rho_nu_svm(*args): return _ml.CvSVMSolver_calc_rho_nu_svm(*args)
    def get_row_svc(*args): return _ml.CvSVMSolver_get_row_svc(*args)
    def get_row_one_class(*args): return _ml.CvSVMSolver_get_row_one_class(*args)
    def get_row_svr(*args): return _ml.CvSVMSolver_get_row_svr(*args)
CvSVMSolver_swigregister = _ml.CvSVMSolver_swigregister
CvSVMSolver_swigregister(CvSVMSolver)

class CvSVMDecisionFunc(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVMDecisionFunc, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVMDecisionFunc, name)
    __repr__ = _swig_repr
    __swig_setmethods__["rho"] = _ml.CvSVMDecisionFunc_rho_set
    __swig_getmethods__["rho"] = _ml.CvSVMDecisionFunc_rho_get
    if _newclass:rho = property(_ml.CvSVMDecisionFunc_rho_get, _ml.CvSVMDecisionFunc_rho_set)
    __swig_setmethods__["sv_count"] = _ml.CvSVMDecisionFunc_sv_count_set
    __swig_getmethods__["sv_count"] = _ml.CvSVMDecisionFunc_sv_count_get
    if _newclass:sv_count = property(_ml.CvSVMDecisionFunc_sv_count_get, _ml.CvSVMDecisionFunc_sv_count_set)
    __swig_setmethods__["alpha"] = _ml.CvSVMDecisionFunc_alpha_set
    __swig_getmethods__["alpha"] = _ml.CvSVMDecisionFunc_alpha_get
    if _newclass:alpha = property(_ml.CvSVMDecisionFunc_alpha_get, _ml.CvSVMDecisionFunc_alpha_set)
    __swig_setmethods__["sv_index"] = _ml.CvSVMDecisionFunc_sv_index_set
    __swig_getmethods__["sv_index"] = _ml.CvSVMDecisionFunc_sv_index_get
    if _newclass:sv_index = property(_ml.CvSVMDecisionFunc_sv_index_get, _ml.CvSVMDecisionFunc_sv_index_set)
    def __init__(self, *args): 
        this = _ml.new_CvSVMDecisionFunc(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvSVMDecisionFunc
    __del__ = lambda self : None;
CvSVMDecisionFunc_swigregister = _ml.CvSVMDecisionFunc_swigregister
CvSVMDecisionFunc_swigregister(CvSVMDecisionFunc)

class CvSVM(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvSVM, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvSVM, name)
    __repr__ = _swig_repr
    C_SVC = _ml.CvSVM_C_SVC
    NU_SVC = _ml.CvSVM_NU_SVC
    ONE_CLASS = _ml.CvSVM_ONE_CLASS
    EPS_SVR = _ml.CvSVM_EPS_SVR
    NU_SVR = _ml.CvSVM_NU_SVR
    LINEAR = _ml.CvSVM_LINEAR
    POLY = _ml.CvSVM_POLY
    RBF = _ml.CvSVM_RBF
    SIGMOID = _ml.CvSVM_SIGMOID
    C = _ml.CvSVM_C
    GAMMA = _ml.CvSVM_GAMMA
    P = _ml.CvSVM_P
    NU = _ml.CvSVM_NU
    COEF = _ml.CvSVM_COEF
    DEGREE = _ml.CvSVM_DEGREE
    __swig_destroy__ = _ml.delete_CvSVM
    __del__ = lambda self : None;
    def __init__(self, *args): 
        this = _ml.new_CvSVM(*args)
        try: self.this.append(this)
        except: self.this = this
    def train(*args): return _ml.CvSVM_train(*args)
    def train_auto(*args): return _ml.CvSVM_train_auto(*args)
    def predict(*args): return _ml.CvSVM_predict(*args)
    def get_support_vector_count(*args): return _ml.CvSVM_get_support_vector_count(*args)
    def get_support_vector(*args): return _ml.CvSVM_get_support_vector(*args)
    def get_params(*args): return _ml.CvSVM_get_params(*args)
    def clear(*args): return _ml.CvSVM_clear(*args)
    __swig_getmethods__["get_default_grid"] = lambda x: _ml.CvSVM_get_default_grid
    if _newclass:get_default_grid = staticmethod(_ml.CvSVM_get_default_grid)
    def write(*args): return _ml.CvSVM_write(*args)
    def read(*args): return _ml.CvSVM_read(*args)
    def get_var_count(*args): return _ml.CvSVM_get_var_count(*args)
CvSVM_swigregister = _ml.CvSVM_swigregister
CvSVM_swigregister(CvSVM)
CvSVM_get_default_grid = _ml.CvSVM_get_default_grid

class CvEMParams(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvEMParams, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvEMParams, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvEMParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_setmethods__["nclusters"] = _ml.CvEMParams_nclusters_set
    __swig_getmethods__["nclusters"] = _ml.CvEMParams_nclusters_get
    if _newclass:nclusters = property(_ml.CvEMParams_nclusters_get, _ml.CvEMParams_nclusters_set)
    __swig_setmethods__["cov_mat_type"] = _ml.CvEMParams_cov_mat_type_set
    __swig_getmethods__["cov_mat_type"] = _ml.CvEMParams_cov_mat_type_get
    if _newclass:cov_mat_type = property(_ml.CvEMParams_cov_mat_type_get, _ml.CvEMParams_cov_mat_type_set)
    __swig_setmethods__["start_step"] = _ml.CvEMParams_start_step_set
    __swig_getmethods__["start_step"] = _ml.CvEMParams_start_step_get
    if _newclass:start_step = property(_ml.CvEMParams_start_step_get, _ml.CvEMParams_start_step_set)
    __swig_setmethods__["probs"] = _ml.CvEMParams_probs_set
    __swig_getmethods__["probs"] = _ml.CvEMParams_probs_get
    if _newclass:probs = property(_ml.CvEMParams_probs_get, _ml.CvEMParams_probs_set)
    __swig_setmethods__["weights"] = _ml.CvEMParams_weights_set
    __swig_getmethods__["weights"] = _ml.CvEMParams_weights_get
    if _newclass:weights = property(_ml.CvEMParams_weights_get, _ml.CvEMParams_weights_set)
    __swig_setmethods__["means"] = _ml.CvEMParams_means_set
    __swig_getmethods__["means"] = _ml.CvEMParams_means_get
    if _newclass:means = property(_ml.CvEMParams_means_get, _ml.CvEMParams_means_set)
    __swig_setmethods__["covs"] = _ml.CvEMParams_covs_set
    __swig_getmethods__["covs"] = _ml.CvEMParams_covs_get
    if _newclass:covs = property(_ml.CvEMParams_covs_get, _ml.CvEMParams_covs_set)
    __swig_setmethods__["term_crit"] = _ml.CvEMParams_term_crit_set
    __swig_getmethods__["term_crit"] = _ml.CvEMParams_term_crit_get
    if _newclass:term_crit = property(_ml.CvEMParams_term_crit_get, _ml.CvEMParams_term_crit_set)
    __swig_destroy__ = _ml.delete_CvEMParams
    __del__ = lambda self : None;
CvEMParams_swigregister = _ml.CvEMParams_swigregister
CvEMParams_swigregister(CvEMParams)

class CvEM(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvEM, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvEM, name)
    __repr__ = _swig_repr
    COV_MAT_SPHERICAL = _ml.CvEM_COV_MAT_SPHERICAL
    COV_MAT_DIAGONAL = _ml.CvEM_COV_MAT_DIAGONAL
    COV_MAT_GENERIC = _ml.CvEM_COV_MAT_GENERIC
    START_E_STEP = _ml.CvEM_START_E_STEP
    START_M_STEP = _ml.CvEM_START_M_STEP
    START_AUTO_STEP = _ml.CvEM_START_AUTO_STEP
    def __init__(self, *args): 
        this = _ml.new_CvEM(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvEM
    __del__ = lambda self : None;
    def train(*args): return _ml.CvEM_train(*args)
    def predict(*args): return _ml.CvEM_predict(*args)
    def clear(*args): return _ml.CvEM_clear(*args)
    def get_nclusters(*args): return _ml.CvEM_get_nclusters(*args)
    def get_means(*args): return _ml.CvEM_get_means(*args)
    def get_weights(*args): return _ml.CvEM_get_weights(*args)
    def get_probs(*args): return _ml.CvEM_get_probs(*args)
    def get_covs(*args): return _ml.CvEM_get_covs(*args)
CvEM_swigregister = _ml.CvEM_swigregister
CvEM_swigregister(CvEM)

class CvPair32s32f(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvPair32s32f, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvPair32s32f, name)
    __repr__ = _swig_repr
    __swig_setmethods__["i"] = _ml.CvPair32s32f_i_set
    __swig_getmethods__["i"] = _ml.CvPair32s32f_i_get
    if _newclass:i = property(_ml.CvPair32s32f_i_get, _ml.CvPair32s32f_i_set)
    __swig_setmethods__["val"] = _ml.CvPair32s32f_val_set
    __swig_getmethods__["val"] = _ml.CvPair32s32f_val_get
    if _newclass:val = property(_ml.CvPair32s32f_val_get, _ml.CvPair32s32f_val_set)
    def __init__(self, *args): 
        this = _ml.new_CvPair32s32f(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvPair32s32f
    __del__ = lambda self : None;
CvPair32s32f_swigregister = _ml.CvPair32s32f_swigregister
CvPair32s32f_swigregister(CvPair32s32f)

class CvDTreeSplit(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvDTreeSplit, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvDTreeSplit, name)
    __repr__ = _swig_repr
    __swig_setmethods__["var_idx"] = _ml.CvDTreeSplit_var_idx_set
    __swig_getmethods__["var_idx"] = _ml.CvDTreeSplit_var_idx_get
    if _newclass:var_idx = property(_ml.CvDTreeSplit_var_idx_get, _ml.CvDTreeSplit_var_idx_set)
    __swig_setmethods__["inversed"] = _ml.CvDTreeSplit_inversed_set
    __swig_getmethods__["inversed"] = _ml.CvDTreeSplit_inversed_get
    if _newclass:inversed = property(_ml.CvDTreeSplit_inversed_get, _ml.CvDTreeSplit_inversed_set)
    __swig_setmethods__["quality"] = _ml.CvDTreeSplit_quality_set
    __swig_getmethods__["quality"] = _ml.CvDTreeSplit_quality_get
    if _newclass:quality = property(_ml.CvDTreeSplit_quality_get, _ml.CvDTreeSplit_quality_set)
    __swig_setmethods__["next"] = _ml.CvDTreeSplit_next_set
    __swig_getmethods__["next"] = _ml.CvDTreeSplit_next_get
    if _newclass:next = property(_ml.CvDTreeSplit_next_get, _ml.CvDTreeSplit_next_set)
    def __init__(self, *args): 
        this = _ml.new_CvDTreeSplit(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvDTreeSplit
    __del__ = lambda self : None;
CvDTreeSplit_swigregister = _ml.CvDTreeSplit_swigregister
CvDTreeSplit_swigregister(CvDTreeSplit)

class CvDTreeNode(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvDTreeNode, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvDTreeNode, name)
    __repr__ = _swig_repr
    __swig_setmethods__["class_idx"] = _ml.CvDTreeNode_class_idx_set
    __swig_getmethods__["class_idx"] = _ml.CvDTreeNode_class_idx_get
    if _newclass:class_idx = property(_ml.CvDTreeNode_class_idx_get, _ml.CvDTreeNode_class_idx_set)
    __swig_setmethods__["Tn"] = _ml.CvDTreeNode_Tn_set
    __swig_getmethods__["Tn"] = _ml.CvDTreeNode_Tn_get
    if _newclass:Tn = property(_ml.CvDTreeNode_Tn_get, _ml.CvDTreeNode_Tn_set)
    __swig_setmethods__["value"] = _ml.CvDTreeNode_value_set
    __swig_getmethods__["value"] = _ml.CvDTreeNode_value_get
    if _newclass:value = property(_ml.CvDTreeNode_value_get, _ml.CvDTreeNode_value_set)
    __swig_setmethods__["parent"] = _ml.CvDTreeNode_parent_set
    __swig_getmethods__["parent"] = _ml.CvDTreeNode_parent_get
    if _newclass:parent = property(_ml.CvDTreeNode_parent_get, _ml.CvDTreeNode_parent_set)
    __swig_setmethods__["left"] = _ml.CvDTreeNode_left_set
    __swig_getmethods__["left"] = _ml.CvDTreeNode_left_get
    if _newclass:left = property(_ml.CvDTreeNode_left_get, _ml.CvDTreeNode_left_set)
    __swig_setmethods__["right"] = _ml.CvDTreeNode_right_set
    __swig_getmethods__["right"] = _ml.CvDTreeNode_right_get
    if _newclass:right = property(_ml.CvDTreeNode_right_get, _ml.CvDTreeNode_right_set)
    __swig_setmethods__["split"] = _ml.CvDTreeNode_split_set
    __swig_getmethods__["split"] = _ml.CvDTreeNode_split_get
    if _newclass:split = property(_ml.CvDTreeNode_split_get, _ml.CvDTreeNode_split_set)
    __swig_setmethods__["sample_count"] = _ml.CvDTreeNode_sample_count_set
    __swig_getmethods__["sample_count"] = _ml.CvDTreeNode_sample_count_get
    if _newclass:sample_count = property(_ml.CvDTreeNode_sample_count_get, _ml.CvDTreeNode_sample_count_set)
    __swig_setmethods__["depth"] = _ml.CvDTreeNode_depth_set
    __swig_getmethods__["depth"] = _ml.CvDTreeNode_depth_get
    if _newclass:depth = property(_ml.CvDTreeNode_depth_get, _ml.CvDTreeNode_depth_set)
    __swig_setmethods__["num_valid"] = _ml.CvDTreeNode_num_valid_set
    __swig_getmethods__["num_valid"] = _ml.CvDTreeNode_num_valid_get
    if _newclass:num_valid = property(_ml.CvDTreeNode_num_valid_get, _ml.CvDTreeNode_num_valid_set)
    __swig_setmethods__["offset"] = _ml.CvDTreeNode_offset_set
    __swig_getmethods__["offset"] = _ml.CvDTreeNode_offset_get
    if _newclass:offset = property(_ml.CvDTreeNode_offset_get, _ml.CvDTreeNode_offset_set)
    __swig_setmethods__["buf_idx"] = _ml.CvDTreeNode_buf_idx_set
    __swig_getmethods__["buf_idx"] = _ml.CvDTreeNode_buf_idx_get
    if _newclass:buf_idx = property(_ml.CvDTreeNode_buf_idx_get, _ml.CvDTreeNode_buf_idx_set)
    __swig_setmethods__["maxlr"] = _ml.CvDTreeNode_maxlr_set
    __swig_getmethods__["maxlr"] = _ml.CvDTreeNode_maxlr_get
    if _newclass:maxlr = property(_ml.CvDTreeNode_maxlr_get, _ml.CvDTreeNode_maxlr_set)
    __swig_setmethods__["complexity"] = _ml.CvDTreeNode_complexity_set
    __swig_getmethods__["complexity"] = _ml.CvDTreeNode_complexity_get
    if _newclass:complexity = property(_ml.CvDTreeNode_complexity_get, _ml.CvDTreeNode_complexity_set)
    __swig_setmethods__["alpha"] = _ml.CvDTreeNode_alpha_set
    __swig_getmethods__["alpha"] = _ml.CvDTreeNode_alpha_get
    if _newclass:alpha = property(_ml.CvDTreeNode_alpha_get, _ml.CvDTreeNode_alpha_set)
    __swig_setmethods__["node_risk"] = _ml.CvDTreeNode_node_risk_set
    __swig_getmethods__["node_risk"] = _ml.CvDTreeNode_node_risk_get
    if _newclass:node_risk = property(_ml.CvDTreeNode_node_risk_get, _ml.CvDTreeNode_node_risk_set)
    __swig_setmethods__["tree_risk"] = _ml.CvDTreeNode_tree_risk_set
    __swig_getmethods__["tree_risk"] = _ml.CvDTreeNode_tree_risk_get
    if _newclass:tree_risk = property(_ml.CvDTreeNode_tree_risk_get, _ml.CvDTreeNode_tree_risk_set)
    __swig_setmethods__["tree_error"] = _ml.CvDTreeNode_tree_error_set
    __swig_getmethods__["tree_error"] = _ml.CvDTreeNode_tree_error_get
    if _newclass:tree_error = property(_ml.CvDTreeNode_tree_error_get, _ml.CvDTreeNode_tree_error_set)
    __swig_setmethods__["cv_Tn"] = _ml.CvDTreeNode_cv_Tn_set
    __swig_getmethods__["cv_Tn"] = _ml.CvDTreeNode_cv_Tn_get
    if _newclass:cv_Tn = property(_ml.CvDTreeNode_cv_Tn_get, _ml.CvDTreeNode_cv_Tn_set)
    __swig_setmethods__["cv_node_risk"] = _ml.CvDTreeNode_cv_node_risk_set
    __swig_getmethods__["cv_node_risk"] = _ml.CvDTreeNode_cv_node_risk_get
    if _newclass:cv_node_risk = property(_ml.CvDTreeNode_cv_node_risk_get, _ml.CvDTreeNode_cv_node_risk_set)
    __swig_setmethods__["cv_node_error"] = _ml.CvDTreeNode_cv_node_error_set
    __swig_getmethods__["cv_node_error"] = _ml.CvDTreeNode_cv_node_error_get
    if _newclass:cv_node_error = property(_ml.CvDTreeNode_cv_node_error_get, _ml.CvDTreeNode_cv_node_error_set)
    def get_num_valid(*args): return _ml.CvDTreeNode_get_num_valid(*args)
    def set_num_valid(*args): return _ml.CvDTreeNode_set_num_valid(*args)
    def __init__(self, *args): 
        this = _ml.new_CvDTreeNode(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvDTreeNode
    __del__ = lambda self : None;
CvDTreeNode_swigregister = _ml.CvDTreeNode_swigregister
CvDTreeNode_swigregister(CvDTreeNode)

class CvDTreeParams(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvDTreeParams, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvDTreeParams, name)
    __repr__ = _swig_repr
    __swig_setmethods__["max_categories"] = _ml.CvDTreeParams_max_categories_set
    __swig_getmethods__["max_categories"] = _ml.CvDTreeParams_max_categories_get
    if _newclass:max_categories = property(_ml.CvDTreeParams_max_categories_get, _ml.CvDTreeParams_max_categories_set)
    __swig_setmethods__["max_depth"] = _ml.CvDTreeParams_max_depth_set
    __swig_getmethods__["max_depth"] = _ml.CvDTreeParams_max_depth_get
    if _newclass:max_depth = property(_ml.CvDTreeParams_max_depth_get, _ml.CvDTreeParams_max_depth_set)
    __swig_setmethods__["min_sample_count"] = _ml.CvDTreeParams_min_sample_count_set
    __swig_getmethods__["min_sample_count"] = _ml.CvDTreeParams_min_sample_count_get
    if _newclass:min_sample_count = property(_ml.CvDTreeParams_min_sample_count_get, _ml.CvDTreeParams_min_sample_count_set)
    __swig_setmethods__["cv_folds"] = _ml.CvDTreeParams_cv_folds_set
    __swig_getmethods__["cv_folds"] = _ml.CvDTreeParams_cv_folds_get
    if _newclass:cv_folds = property(_ml.CvDTreeParams_cv_folds_get, _ml.CvDTreeParams_cv_folds_set)
    __swig_setmethods__["use_surrogates"] = _ml.CvDTreeParams_use_surrogates_set
    __swig_getmethods__["use_surrogates"] = _ml.CvDTreeParams_use_surrogates_get
    if _newclass:use_surrogates = property(_ml.CvDTreeParams_use_surrogates_get, _ml.CvDTreeParams_use_surrogates_set)
    __swig_setmethods__["use_1se_rule"] = _ml.CvDTreeParams_use_1se_rule_set
    __swig_getmethods__["use_1se_rule"] = _ml.CvDTreeParams_use_1se_rule_get
    if _newclass:use_1se_rule = property(_ml.CvDTreeParams_use_1se_rule_get, _ml.CvDTreeParams_use_1se_rule_set)
    __swig_setmethods__["truncate_pruned_tree"] = _ml.CvDTreeParams_truncate_pruned_tree_set
    __swig_getmethods__["truncate_pruned_tree"] = _ml.CvDTreeParams_truncate_pruned_tree_get
    if _newclass:truncate_pruned_tree = property(_ml.CvDTreeParams_truncate_pruned_tree_get, _ml.CvDTreeParams_truncate_pruned_tree_set)
    __swig_setmethods__["regression_accuracy"] = _ml.CvDTreeParams_regression_accuracy_set
    __swig_getmethods__["regression_accuracy"] = _ml.CvDTreeParams_regression_accuracy_get
    if _newclass:regression_accuracy = property(_ml.CvDTreeParams_regression_accuracy_get, _ml.CvDTreeParams_regression_accuracy_set)
    __swig_setmethods__["priors"] = _ml.CvDTreeParams_priors_set
    __swig_getmethods__["priors"] = _ml.CvDTreeParams_priors_get
    if _newclass:priors = property(_ml.CvDTreeParams_priors_get, _ml.CvDTreeParams_priors_set)
    def __init__(self, *args): 
        this = _ml.new_CvDTreeParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvDTreeParams
    __del__ = lambda self : None;
CvDTreeParams_swigregister = _ml.CvDTreeParams_swigregister
CvDTreeParams_swigregister(CvDTreeParams)

class CvDTreeTrainData(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvDTreeTrainData, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvDTreeTrainData, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvDTreeTrainData(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvDTreeTrainData
    __del__ = lambda self : None;
    def set_data(*args): return _ml.CvDTreeTrainData_set_data(*args)
    def get_vectors(*args): return _ml.CvDTreeTrainData_get_vectors(*args)
    def subsample_data(*args): return _ml.CvDTreeTrainData_subsample_data(*args)
    def write_params(*args): return _ml.CvDTreeTrainData_write_params(*args)
    def read_params(*args): return _ml.CvDTreeTrainData_read_params(*args)
    def clear(*args): return _ml.CvDTreeTrainData_clear(*args)
    def get_num_classes(*args): return _ml.CvDTreeTrainData_get_num_classes(*args)
    def get_var_type(*args): return _ml.CvDTreeTrainData_get_var_type(*args)
    def get_work_var_count(*args): return _ml.CvDTreeTrainData_get_work_var_count(*args)
    def get_class_labels(*args): return _ml.CvDTreeTrainData_get_class_labels(*args)
    def get_ord_responses(*args): return _ml.CvDTreeTrainData_get_ord_responses(*args)
    def get_labels(*args): return _ml.CvDTreeTrainData_get_labels(*args)
    def get_cat_var_data(*args): return _ml.CvDTreeTrainData_get_cat_var_data(*args)
    def get_ord_var_data(*args): return _ml.CvDTreeTrainData_get_ord_var_data(*args)
    def get_child_buf_idx(*args): return _ml.CvDTreeTrainData_get_child_buf_idx(*args)
    def set_params(*args): return _ml.CvDTreeTrainData_set_params(*args)
    def new_node(*args): return _ml.CvDTreeTrainData_new_node(*args)
    def new_split_ord(*args): return _ml.CvDTreeTrainData_new_split_ord(*args)
    def new_split_cat(*args): return _ml.CvDTreeTrainData_new_split_cat(*args)
    def free_node_data(*args): return _ml.CvDTreeTrainData_free_node_data(*args)
    def free_train_data(*args): return _ml.CvDTreeTrainData_free_train_data(*args)
    def free_node(*args): return _ml.CvDTreeTrainData_free_node(*args)
    __swig_setmethods__["sample_count"] = _ml.CvDTreeTrainData_sample_count_set
    __swig_getmethods__["sample_count"] = _ml.CvDTreeTrainData_sample_count_get
    if _newclass:sample_count = property(_ml.CvDTreeTrainData_sample_count_get, _ml.CvDTreeTrainData_sample_count_set)
    __swig_setmethods__["var_all"] = _ml.CvDTreeTrainData_var_all_set
    __swig_getmethods__["var_all"] = _ml.CvDTreeTrainData_var_all_get
    if _newclass:var_all = property(_ml.CvDTreeTrainData_var_all_get, _ml.CvDTreeTrainData_var_all_set)
    __swig_setmethods__["var_count"] = _ml.CvDTreeTrainData_var_count_set
    __swig_getmethods__["var_count"] = _ml.CvDTreeTrainData_var_count_get
    if _newclass:var_count = property(_ml.CvDTreeTrainData_var_count_get, _ml.CvDTreeTrainData_var_count_set)
    __swig_setmethods__["max_c_count"] = _ml.CvDTreeTrainData_max_c_count_set
    __swig_getmethods__["max_c_count"] = _ml.CvDTreeTrainData_max_c_count_get
    if _newclass:max_c_count = property(_ml.CvDTreeTrainData_max_c_count_get, _ml.CvDTreeTrainData_max_c_count_set)
    __swig_setmethods__["ord_var_count"] = _ml.CvDTreeTrainData_ord_var_count_set
    __swig_getmethods__["ord_var_count"] = _ml.CvDTreeTrainData_ord_var_count_get
    if _newclass:ord_var_count = property(_ml.CvDTreeTrainData_ord_var_count_get, _ml.CvDTreeTrainData_ord_var_count_set)
    __swig_setmethods__["cat_var_count"] = _ml.CvDTreeTrainData_cat_var_count_set
    __swig_getmethods__["cat_var_count"] = _ml.CvDTreeTrainData_cat_var_count_get
    if _newclass:cat_var_count = property(_ml.CvDTreeTrainData_cat_var_count_get, _ml.CvDTreeTrainData_cat_var_count_set)
    __swig_setmethods__["have_labels"] = _ml.CvDTreeTrainData_have_labels_set
    __swig_getmethods__["have_labels"] = _ml.CvDTreeTrainData_have_labels_get
    if _newclass:have_labels = property(_ml.CvDTreeTrainData_have_labels_get, _ml.CvDTreeTrainData_have_labels_set)
    __swig_setmethods__["have_priors"] = _ml.CvDTreeTrainData_have_priors_set
    __swig_getmethods__["have_priors"] = _ml.CvDTreeTrainData_have_priors_get
    if _newclass:have_priors = property(_ml.CvDTreeTrainData_have_priors_get, _ml.CvDTreeTrainData_have_priors_set)
    __swig_setmethods__["is_classifier"] = _ml.CvDTreeTrainData_is_classifier_set
    __swig_getmethods__["is_classifier"] = _ml.CvDTreeTrainData_is_classifier_get
    if _newclass:is_classifier = property(_ml.CvDTreeTrainData_is_classifier_get, _ml.CvDTreeTrainData_is_classifier_set)
    __swig_setmethods__["buf_count"] = _ml.CvDTreeTrainData_buf_count_set
    __swig_getmethods__["buf_count"] = _ml.CvDTreeTrainData_buf_count_get
    if _newclass:buf_count = property(_ml.CvDTreeTrainData_buf_count_get, _ml.CvDTreeTrainData_buf_count_set)
    __swig_setmethods__["buf_size"] = _ml.CvDTreeTrainData_buf_size_set
    __swig_getmethods__["buf_size"] = _ml.CvDTreeTrainData_buf_size_get
    if _newclass:buf_size = property(_ml.CvDTreeTrainData_buf_size_get, _ml.CvDTreeTrainData_buf_size_set)
    __swig_setmethods__["shared"] = _ml.CvDTreeTrainData_shared_set
    __swig_getmethods__["shared"] = _ml.CvDTreeTrainData_shared_get
    if _newclass:shared = property(_ml.CvDTreeTrainData_shared_get, _ml.CvDTreeTrainData_shared_set)
    __swig_setmethods__["cat_count"] = _ml.CvDTreeTrainData_cat_count_set
    __swig_getmethods__["cat_count"] = _ml.CvDTreeTrainData_cat_count_get
    if _newclass:cat_count = property(_ml.CvDTreeTrainData_cat_count_get, _ml.CvDTreeTrainData_cat_count_set)
    __swig_setmethods__["cat_ofs"] = _ml.CvDTreeTrainData_cat_ofs_set
    __swig_getmethods__["cat_ofs"] = _ml.CvDTreeTrainData_cat_ofs_get
    if _newclass:cat_ofs = property(_ml.CvDTreeTrainData_cat_ofs_get, _ml.CvDTreeTrainData_cat_ofs_set)
    __swig_setmethods__["cat_map"] = _ml.CvDTreeTrainData_cat_map_set
    __swig_getmethods__["cat_map"] = _ml.CvDTreeTrainData_cat_map_get
    if _newclass:cat_map = property(_ml.CvDTreeTrainData_cat_map_get, _ml.CvDTreeTrainData_cat_map_set)
    __swig_setmethods__["counts"] = _ml.CvDTreeTrainData_counts_set
    __swig_getmethods__["counts"] = _ml.CvDTreeTrainData_counts_get
    if _newclass:counts = property(_ml.CvDTreeTrainData_counts_get, _ml.CvDTreeTrainData_counts_set)
    __swig_setmethods__["buf"] = _ml.CvDTreeTrainData_buf_set
    __swig_getmethods__["buf"] = _ml.CvDTreeTrainData_buf_get
    if _newclass:buf = property(_ml.CvDTreeTrainData_buf_get, _ml.CvDTreeTrainData_buf_set)
    __swig_setmethods__["direction"] = _ml.CvDTreeTrainData_direction_set
    __swig_getmethods__["direction"] = _ml.CvDTreeTrainData_direction_get
    if _newclass:direction = property(_ml.CvDTreeTrainData_direction_get, _ml.CvDTreeTrainData_direction_set)
    __swig_setmethods__["split_buf"] = _ml.CvDTreeTrainData_split_buf_set
    __swig_getmethods__["split_buf"] = _ml.CvDTreeTrainData_split_buf_get
    if _newclass:split_buf = property(_ml.CvDTreeTrainData_split_buf_get, _ml.CvDTreeTrainData_split_buf_set)
    __swig_setmethods__["var_idx"] = _ml.CvDTreeTrainData_var_idx_set
    __swig_getmethods__["var_idx"] = _ml.CvDTreeTrainData_var_idx_get
    if _newclass:var_idx = property(_ml.CvDTreeTrainData_var_idx_get, _ml.CvDTreeTrainData_var_idx_set)
    __swig_setmethods__["var_type"] = _ml.CvDTreeTrainData_var_type_set
    __swig_getmethods__["var_type"] = _ml.CvDTreeTrainData_var_type_get
    if _newclass:var_type = property(_ml.CvDTreeTrainData_var_type_get, _ml.CvDTreeTrainData_var_type_set)
    __swig_setmethods__["priors"] = _ml.CvDTreeTrainData_priors_set
    __swig_getmethods__["priors"] = _ml.CvDTreeTrainData_priors_get
    if _newclass:priors = property(_ml.CvDTreeTrainData_priors_get, _ml.CvDTreeTrainData_priors_set)
    __swig_setmethods__["priors_mult"] = _ml.CvDTreeTrainData_priors_mult_set
    __swig_getmethods__["priors_mult"] = _ml.CvDTreeTrainData_priors_mult_get
    if _newclass:priors_mult = property(_ml.CvDTreeTrainData_priors_mult_get, _ml.CvDTreeTrainData_priors_mult_set)
    __swig_setmethods__["params"] = _ml.CvDTreeTrainData_params_set
    __swig_getmethods__["params"] = _ml.CvDTreeTrainData_params_get
    if _newclass:params = property(_ml.CvDTreeTrainData_params_get, _ml.CvDTreeTrainData_params_set)
    __swig_setmethods__["tree_storage"] = _ml.CvDTreeTrainData_tree_storage_set
    __swig_getmethods__["tree_storage"] = _ml.CvDTreeTrainData_tree_storage_get
    if _newclass:tree_storage = property(_ml.CvDTreeTrainData_tree_storage_get, _ml.CvDTreeTrainData_tree_storage_set)
    __swig_setmethods__["temp_storage"] = _ml.CvDTreeTrainData_temp_storage_set
    __swig_getmethods__["temp_storage"] = _ml.CvDTreeTrainData_temp_storage_get
    if _newclass:temp_storage = property(_ml.CvDTreeTrainData_temp_storage_get, _ml.CvDTreeTrainData_temp_storage_set)
    __swig_setmethods__["data_root"] = _ml.CvDTreeTrainData_data_root_set
    __swig_getmethods__["data_root"] = _ml.CvDTreeTrainData_data_root_get
    if _newclass:data_root = property(_ml.CvDTreeTrainData_data_root_get, _ml.CvDTreeTrainData_data_root_set)
    __swig_setmethods__["node_heap"] = _ml.CvDTreeTrainData_node_heap_set
    __swig_getmethods__["node_heap"] = _ml.CvDTreeTrainData_node_heap_get
    if _newclass:node_heap = property(_ml.CvDTreeTrainData_node_heap_get, _ml.CvDTreeTrainData_node_heap_set)
    __swig_setmethods__["split_heap"] = _ml.CvDTreeTrainData_split_heap_set
    __swig_getmethods__["split_heap"] = _ml.CvDTreeTrainData_split_heap_get
    if _newclass:split_heap = property(_ml.CvDTreeTrainData_split_heap_get, _ml.CvDTreeTrainData_split_heap_set)
    __swig_setmethods__["cv_heap"] = _ml.CvDTreeTrainData_cv_heap_set
    __swig_getmethods__["cv_heap"] = _ml.CvDTreeTrainData_cv_heap_get
    if _newclass:cv_heap = property(_ml.CvDTreeTrainData_cv_heap_get, _ml.CvDTreeTrainData_cv_heap_set)
    __swig_setmethods__["nv_heap"] = _ml.CvDTreeTrainData_nv_heap_set
    __swig_getmethods__["nv_heap"] = _ml.CvDTreeTrainData_nv_heap_get
    if _newclass:nv_heap = property(_ml.CvDTreeTrainData_nv_heap_get, _ml.CvDTreeTrainData_nv_heap_set)
    __swig_setmethods__["rng"] = _ml.CvDTreeTrainData_rng_set
    __swig_getmethods__["rng"] = _ml.CvDTreeTrainData_rng_get
    if _newclass:rng = property(_ml.CvDTreeTrainData_rng_get, _ml.CvDTreeTrainData_rng_set)
CvDTreeTrainData_swigregister = _ml.CvDTreeTrainData_swigregister
CvDTreeTrainData_swigregister(CvDTreeTrainData)

class CvDTree(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvDTree, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvDTree, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvDTree(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvDTree
    __del__ = lambda self : None;
    def train(*args): return _ml.CvDTree_train(*args)
    def predict(*args): return _ml.CvDTree_predict(*args)
    def get_var_importance(*args): return _ml.CvDTree_get_var_importance(*args)
    def clear(*args): return _ml.CvDTree_clear(*args)
    def read(*args): return _ml.CvDTree_read(*args)
    def write(*args): return _ml.CvDTree_write(*args)
    def get_root(*args): return _ml.CvDTree_get_root(*args)
    def get_pruned_tree_idx(*args): return _ml.CvDTree_get_pruned_tree_idx(*args)
    def get_data(*args): return _ml.CvDTree_get_data(*args)
CvDTree_swigregister = _ml.CvDTree_swigregister
CvDTree_swigregister(CvDTree)

class CvForestTree(CvDTree):
    __swig_setmethods__ = {}
    for _s in [CvDTree]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvForestTree, name, value)
    __swig_getmethods__ = {}
    for _s in [CvDTree]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvForestTree, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvForestTree(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvForestTree
    __del__ = lambda self : None;
    def get_var_count(*args): return _ml.CvForestTree_get_var_count(*args)
    def train(*args): return _ml.CvForestTree_train(*args)
    def read(*args): return _ml.CvForestTree_read(*args)
CvForestTree_swigregister = _ml.CvForestTree_swigregister
CvForestTree_swigregister(CvForestTree)

class CvRTParams(CvDTreeParams):
    __swig_setmethods__ = {}
    for _s in [CvDTreeParams]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvRTParams, name, value)
    __swig_getmethods__ = {}
    for _s in [CvDTreeParams]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvRTParams, name)
    __repr__ = _swig_repr
    __swig_setmethods__["calc_var_importance"] = _ml.CvRTParams_calc_var_importance_set
    __swig_getmethods__["calc_var_importance"] = _ml.CvRTParams_calc_var_importance_get
    if _newclass:calc_var_importance = property(_ml.CvRTParams_calc_var_importance_get, _ml.CvRTParams_calc_var_importance_set)
    __swig_setmethods__["nactive_vars"] = _ml.CvRTParams_nactive_vars_set
    __swig_getmethods__["nactive_vars"] = _ml.CvRTParams_nactive_vars_get
    if _newclass:nactive_vars = property(_ml.CvRTParams_nactive_vars_get, _ml.CvRTParams_nactive_vars_set)
    __swig_setmethods__["term_crit"] = _ml.CvRTParams_term_crit_set
    __swig_getmethods__["term_crit"] = _ml.CvRTParams_term_crit_get
    if _newclass:term_crit = property(_ml.CvRTParams_term_crit_get, _ml.CvRTParams_term_crit_set)
    def __init__(self, *args): 
        this = _ml.new_CvRTParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvRTParams
    __del__ = lambda self : None;
CvRTParams_swigregister = _ml.CvRTParams_swigregister
CvRTParams_swigregister(CvRTParams)

class CvRTrees(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvRTrees, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvRTrees, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvRTrees(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvRTrees
    __del__ = lambda self : None;
    def train(*args): return _ml.CvRTrees_train(*args)
    def predict(*args): return _ml.CvRTrees_predict(*args)
    def clear(*args): return _ml.CvRTrees_clear(*args)
    def get_var_importance(*args): return _ml.CvRTrees_get_var_importance(*args)
    def get_proximity(*args): return _ml.CvRTrees_get_proximity(*args)
    def read(*args): return _ml.CvRTrees_read(*args)
    def write(*args): return _ml.CvRTrees_write(*args)
    def get_active_var_mask(*args): return _ml.CvRTrees_get_active_var_mask(*args)
    def get_rng(*args): return _ml.CvRTrees_get_rng(*args)
    def get_tree_count(*args): return _ml.CvRTrees_get_tree_count(*args)
    def get_tree(*args): return _ml.CvRTrees_get_tree(*args)
CvRTrees_swigregister = _ml.CvRTrees_swigregister
CvRTrees_swigregister(CvRTrees)

class CvBoostParams(CvDTreeParams):
    __swig_setmethods__ = {}
    for _s in [CvDTreeParams]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvBoostParams, name, value)
    __swig_getmethods__ = {}
    for _s in [CvDTreeParams]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvBoostParams, name)
    __repr__ = _swig_repr
    __swig_setmethods__["boost_type"] = _ml.CvBoostParams_boost_type_set
    __swig_getmethods__["boost_type"] = _ml.CvBoostParams_boost_type_get
    if _newclass:boost_type = property(_ml.CvBoostParams_boost_type_get, _ml.CvBoostParams_boost_type_set)
    __swig_setmethods__["weak_count"] = _ml.CvBoostParams_weak_count_set
    __swig_getmethods__["weak_count"] = _ml.CvBoostParams_weak_count_get
    if _newclass:weak_count = property(_ml.CvBoostParams_weak_count_get, _ml.CvBoostParams_weak_count_set)
    __swig_setmethods__["split_criteria"] = _ml.CvBoostParams_split_criteria_set
    __swig_getmethods__["split_criteria"] = _ml.CvBoostParams_split_criteria_get
    if _newclass:split_criteria = property(_ml.CvBoostParams_split_criteria_get, _ml.CvBoostParams_split_criteria_set)
    __swig_setmethods__["weight_trim_rate"] = _ml.CvBoostParams_weight_trim_rate_set
    __swig_getmethods__["weight_trim_rate"] = _ml.CvBoostParams_weight_trim_rate_get
    if _newclass:weight_trim_rate = property(_ml.CvBoostParams_weight_trim_rate_get, _ml.CvBoostParams_weight_trim_rate_set)
    def __init__(self, *args): 
        this = _ml.new_CvBoostParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvBoostParams
    __del__ = lambda self : None;
CvBoostParams_swigregister = _ml.CvBoostParams_swigregister
CvBoostParams_swigregister(CvBoostParams)

class CvBoostTree(CvDTree):
    __swig_setmethods__ = {}
    for _s in [CvDTree]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvBoostTree, name, value)
    __swig_getmethods__ = {}
    for _s in [CvDTree]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvBoostTree, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvBoostTree(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvBoostTree
    __del__ = lambda self : None;
    def scale(*args): return _ml.CvBoostTree_scale(*args)
    def clear(*args): return _ml.CvBoostTree_clear(*args)
    def train(*args): return _ml.CvBoostTree_train(*args)
    def read(*args): return _ml.CvBoostTree_read(*args)
CvBoostTree_swigregister = _ml.CvBoostTree_swigregister
CvBoostTree_swigregister(CvBoostTree)

class CvBoost(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvBoost, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvBoost, name)
    __repr__ = _swig_repr
    DISCRETE = _ml.CvBoost_DISCRETE
    REAL = _ml.CvBoost_REAL
    LOGIT = _ml.CvBoost_LOGIT
    GENTLE = _ml.CvBoost_GENTLE
    DEFAULT = _ml.CvBoost_DEFAULT
    GINI = _ml.CvBoost_GINI
    MISCLASS = _ml.CvBoost_MISCLASS
    SQERR = _ml.CvBoost_SQERR
    __swig_destroy__ = _ml.delete_CvBoost
    __del__ = lambda self : None;
    def __init__(self, *args): 
        this = _ml.new_CvBoost(*args)
        try: self.this.append(this)
        except: self.this = this
    def train(*args): return _ml.CvBoost_train(*args)
    def predict(*args): return _ml.CvBoost_predict(*args)
    def prune(*args): return _ml.CvBoost_prune(*args)
    def clear(*args): return _ml.CvBoost_clear(*args)
    def write(*args): return _ml.CvBoost_write(*args)
    def read(*args): return _ml.CvBoost_read(*args)
    def get_weak_predictors(*args): return _ml.CvBoost_get_weak_predictors(*args)
    def get_weights(*args): return _ml.CvBoost_get_weights(*args)
    def get_subtree_weights(*args): return _ml.CvBoost_get_subtree_weights(*args)
    def get_weak_response(*args): return _ml.CvBoost_get_weak_response(*args)
    def get_params(*args): return _ml.CvBoost_get_params(*args)
CvBoost_swigregister = _ml.CvBoost_swigregister
CvBoost_swigregister(CvBoost)

class CvANN_MLP_TrainParams(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvANN_MLP_TrainParams, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CvANN_MLP_TrainParams, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvANN_MLP_TrainParams(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvANN_MLP_TrainParams
    __del__ = lambda self : None;
    BACKPROP = _ml.CvANN_MLP_TrainParams_BACKPROP
    RPROP = _ml.CvANN_MLP_TrainParams_RPROP
    __swig_setmethods__["term_crit"] = _ml.CvANN_MLP_TrainParams_term_crit_set
    __swig_getmethods__["term_crit"] = _ml.CvANN_MLP_TrainParams_term_crit_get
    if _newclass:term_crit = property(_ml.CvANN_MLP_TrainParams_term_crit_get, _ml.CvANN_MLP_TrainParams_term_crit_set)
    __swig_setmethods__["train_method"] = _ml.CvANN_MLP_TrainParams_train_method_set
    __swig_getmethods__["train_method"] = _ml.CvANN_MLP_TrainParams_train_method_get
    if _newclass:train_method = property(_ml.CvANN_MLP_TrainParams_train_method_get, _ml.CvANN_MLP_TrainParams_train_method_set)
    __swig_setmethods__["bp_dw_scale"] = _ml.CvANN_MLP_TrainParams_bp_dw_scale_set
    __swig_getmethods__["bp_dw_scale"] = _ml.CvANN_MLP_TrainParams_bp_dw_scale_get
    if _newclass:bp_dw_scale = property(_ml.CvANN_MLP_TrainParams_bp_dw_scale_get, _ml.CvANN_MLP_TrainParams_bp_dw_scale_set)
    __swig_setmethods__["bp_moment_scale"] = _ml.CvANN_MLP_TrainParams_bp_moment_scale_set
    __swig_getmethods__["bp_moment_scale"] = _ml.CvANN_MLP_TrainParams_bp_moment_scale_get
    if _newclass:bp_moment_scale = property(_ml.CvANN_MLP_TrainParams_bp_moment_scale_get, _ml.CvANN_MLP_TrainParams_bp_moment_scale_set)
    __swig_setmethods__["rp_dw0"] = _ml.CvANN_MLP_TrainParams_rp_dw0_set
    __swig_getmethods__["rp_dw0"] = _ml.CvANN_MLP_TrainParams_rp_dw0_get
    if _newclass:rp_dw0 = property(_ml.CvANN_MLP_TrainParams_rp_dw0_get, _ml.CvANN_MLP_TrainParams_rp_dw0_set)
    __swig_setmethods__["rp_dw_plus"] = _ml.CvANN_MLP_TrainParams_rp_dw_plus_set
    __swig_getmethods__["rp_dw_plus"] = _ml.CvANN_MLP_TrainParams_rp_dw_plus_get
    if _newclass:rp_dw_plus = property(_ml.CvANN_MLP_TrainParams_rp_dw_plus_get, _ml.CvANN_MLP_TrainParams_rp_dw_plus_set)
    __swig_setmethods__["rp_dw_minus"] = _ml.CvANN_MLP_TrainParams_rp_dw_minus_set
    __swig_getmethods__["rp_dw_minus"] = _ml.CvANN_MLP_TrainParams_rp_dw_minus_get
    if _newclass:rp_dw_minus = property(_ml.CvANN_MLP_TrainParams_rp_dw_minus_get, _ml.CvANN_MLP_TrainParams_rp_dw_minus_set)
    __swig_setmethods__["rp_dw_min"] = _ml.CvANN_MLP_TrainParams_rp_dw_min_set
    __swig_getmethods__["rp_dw_min"] = _ml.CvANN_MLP_TrainParams_rp_dw_min_get
    if _newclass:rp_dw_min = property(_ml.CvANN_MLP_TrainParams_rp_dw_min_get, _ml.CvANN_MLP_TrainParams_rp_dw_min_set)
    __swig_setmethods__["rp_dw_max"] = _ml.CvANN_MLP_TrainParams_rp_dw_max_set
    __swig_getmethods__["rp_dw_max"] = _ml.CvANN_MLP_TrainParams_rp_dw_max_get
    if _newclass:rp_dw_max = property(_ml.CvANN_MLP_TrainParams_rp_dw_max_get, _ml.CvANN_MLP_TrainParams_rp_dw_max_set)
CvANN_MLP_TrainParams_swigregister = _ml.CvANN_MLP_TrainParams_swigregister
CvANN_MLP_TrainParams_swigregister(CvANN_MLP_TrainParams)

class CvANN_MLP(CvStatModel):
    __swig_setmethods__ = {}
    for _s in [CvStatModel]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CvANN_MLP, name, value)
    __swig_getmethods__ = {}
    for _s in [CvStatModel]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CvANN_MLP, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _ml.new_CvANN_MLP(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ml.delete_CvANN_MLP
    __del__ = lambda self : None;
    def create(*args): return _ml.CvANN_MLP_create(*args)
    def train(*args): return _ml.CvANN_MLP_train(*args)
    def predict(*args): return _ml.CvANN_MLP_predict(*args)
    def clear(*args): return _ml.CvANN_MLP_clear(*args)
    IDENTITY = _ml.CvANN_MLP_IDENTITY
    SIGMOID_SYM = _ml.CvANN_MLP_SIGMOID_SYM
    GAUSSIAN = _ml.CvANN_MLP_GAUSSIAN
    UPDATE_WEIGHTS = _ml.CvANN_MLP_UPDATE_WEIGHTS
    NO_INPUT_SCALE = _ml.CvANN_MLP_NO_INPUT_SCALE
    NO_OUTPUT_SCALE = _ml.CvANN_MLP_NO_OUTPUT_SCALE
    def read(*args): return _ml.CvANN_MLP_read(*args)
    def write(*args): return _ml.CvANN_MLP_write(*args)
    def get_layer_count(*args): return _ml.CvANN_MLP_get_layer_count(*args)
    def get_layer_sizes(*args): return _ml.CvANN_MLP_get_layer_sizes(*args)
    def get_weights(*args): return _ml.CvANN_MLP_get_weights(*args)
CvANN_MLP_swigregister = _ml.CvANN_MLP_swigregister
CvANN_MLP_swigregister(CvANN_MLP)

cvRandMVNormal = _ml.cvRandMVNormal
cvRandGaussMixture = _ml.cvRandGaussMixture
CV_TS_CONCENTRIC_SPHERES = _ml.CV_TS_CONCENTRIC_SPHERES
cvCreateTestSet = _ml.cvCreateTestSet
cvCompleteSymm = _ml.cvCompleteSymm


