// <:copyright-BRCM:2013:DUAL/GPL:standard
// 
//    Copyright (c) 2013 Broadcom Corporation
//    All Rights Reserved
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 2, as published by
// the Free Software Foundation (the "GPL").
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// 
// A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
// writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
// 
// :>
/*
 * gpon object header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_AG_GPON_H_
#define _RDPA_AG_GPON_H_

/** \addtogroup gpon
 * @{
 */


/** Get gpon type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a gpon object.
 * \return gpon type handle
 */
bdmf_type_handle rdpa_gpon_drv(void);

/* gpon: Attribute types */
typedef enum {
    rdpa_gpon_attr_link_activate = 0, /* link_activate : RW : enum/4 : PON Link_activate / deactivate */
    rdpa_gpon_attr_link_cfg = 1, /* link_cfg : RW : aggregate/64 gpon_link_cfg(rdpa_gpon_link_cfg_t) : PON Link Configuration */
    rdpa_gpon_attr_pon_link_state = 2, /* pon_link_state : R : aggregate/12 gpon_link_state(rdpa_pon_link_state) : Link state */
    rdpa_gpon_attr_onu_id = 3, /* onu_id : R : number/4 : ONU ID */
    rdpa_gpon_attr_onu_sn = 4, /* onu_sn : RW : aggregate/8 onu_sn(rdpa_onu_sn_t) : ONU serial number */
    rdpa_gpon_attr_password = 5, /* password : RW : buffer/10 : ONU password */
    rdpa_gpon_attr_user_ic = 6, /* user_ic : RW : pointer/4 : User indication callback */
    rdpa_gpon_attr_link_stat = 7, /* link_stat : R : aggregate/32 gpon_link_stat(rdpa_gpon_stat_t) : Link statistics */
    rdpa_gpon_attr_overhead_cfg = 8, /* overhead_cfg : R : aggregate/19 gpon_overhead_cfg(rdpa_gpon_overhead_cfg_t) : Overhead configuration */
    rdpa_gpon_attr_transceiver_power_level = 9, /* transceiver_power_level : R : number/1 : Transceiver power level configuration */
    rdpa_gpon_attr_equalization_delay = 10, /* equalization_delay : R : number/4 : Equalization delay */
    rdpa_gpon_attr_encryption_key = 11, /* encryption_key : R : buffer/16 : Encryption key */
    rdpa_gpon_attr_tcont_counter_assigment = 12, /* tcont_counter_assigment : RW : number/4 : TCONT counter assigment */
    rdpa_gpon_attr_ds_fec_state = 13, /* ds_fec_state : R : bool/1 : DS FEC enable state */
    rdpa_gpon_attr_fec_stat = 14, /* fec_stat : R : aggregate/12 fec_stat(rdpa_fec_stat_t) : FEC statistics */
    rdpa_gpon_attr_send_ploam = 15, /* send_ploam : W : aggregate/16 send_ploam(rdpa_send_ploam_params_t) : Send ploam */
    rdpa_gpon_attr_dba_interval = 16, /* dba_interval : RW : enum/4 : DBA Status Report */
    rdpa_gpon_attr_prbs = 17, /* prbs : RW : aggregate/10 prbs(rdpa_prbs_t) : PRBS */
    rdpa_gpon_attr_rogue_onu = 18, /* rogue_onu : RW : aggregate/16 rogue_onu(rdpa_rogue_onu_t) : rogue onu */
    rdpa_gpon_attr_gem_block_size = 19, /* gem_block_size : RW : number/4 : Gem block size */
    rdpa_gpon_attr_gem_enable = 20, /* gem_enable : RWF : bool/1[231(object)] : Enable GEM */
    rdpa_gpon_attr_gem_ds_cfg = 21, /* gem_ds_cfg : RWF : aggregate/9[231(object)] gem_ds_cfg(rdpa_gpon_gem_ds_cfg_t) : Downstream GEM configuration */
    rdpa_gpon_attr_gem_encryption = 22, /* gem_encryption : RWF : bool/1[231(object)] : Downstream GEM flow Encryption mode */
    rdpa_gpon_attr_tcont_alloc_id = 23, /* tcont_alloc_id : RWDF : number/4[32(object)] : TCONT Alloc ID */
    rdpa_gpon_attr_tcont_assign_ploam_flag = 24, /* tcont_assign_ploam_flag : RF : bool/1[32(object)] : TCONT Assign alloc id message arrived */
    rdpa_gpon_attr_tcont_stat = 25, /* tcont_stat : RF : aggregate/16[32(object)] tcont_stat(rdpa_tcont_stat_t) : TCONT statistics */
    rdpa_gpon_attr_tcont_flush = 26, /* tcont_flush : W : bool/1[32(object)] : Flush TCONT Front End Buffer and BBH Queue */
} rdpa_gpon_attr_types;

extern int (*f_rdpa_gpon_get)(bdmf_object_handle *pmo);

/** Get gpon object.

 * This function returns gpon object instance.
 * \param[out] gpon_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_gpon_get(bdmf_object_handle *gpon_obj);

/** Get gpon/link_activate attribute.
 *
 * Get PON Link_activate / deactivate.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  link_activate_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_link_activate_get(bdmf_object_handle mo_, rdpa_link_activate_t *link_activate_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_link_activate, &_nn_);
    *link_activate_ = (rdpa_link_activate_t)_nn_;
    return _rc_;
}


/** Set gpon/link_activate attribute.
 *
 * Set PON Link_activate / deactivate.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   link_activate_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_link_activate_set(bdmf_object_handle mo_, rdpa_link_activate_t link_activate_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_gpon_attr_link_activate, link_activate_);
}


/** Get gpon/link_cfg attribute.
 *
 * Get PON Link Configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  link_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_link_cfg_get(bdmf_object_handle mo_, rdpa_gpon_link_cfg_t * link_cfg_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_link_cfg, link_cfg_, sizeof(*link_cfg_));
}


/** Set gpon/link_cfg attribute.
 *
 * Set PON Link Configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   link_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_link_cfg_set(bdmf_object_handle mo_, const rdpa_gpon_link_cfg_t * link_cfg_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_link_cfg, link_cfg_, sizeof(*link_cfg_));
}


/** Get gpon/pon_link_state attribute.
 *
 * Get Link state.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  pon_link_state_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_pon_link_state_get(bdmf_object_handle mo_, rdpa_pon_link_state * pon_link_state_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_pon_link_state, pon_link_state_, sizeof(*pon_link_state_));
}


/** Get gpon/onu_id attribute.
 *
 * Get ONU ID.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  onu_id_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_onu_id_get(bdmf_object_handle mo_, bdmf_number *onu_id_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_onu_id, &_nn_);
    *onu_id_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Get gpon/onu_sn attribute.
 *
 * Get ONU serial number.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  onu_sn_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_onu_sn_get(bdmf_object_handle mo_, rdpa_onu_sn_t * onu_sn_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_onu_sn, onu_sn_, sizeof(*onu_sn_));
}


/** Set gpon/onu_sn attribute.
 *
 * Set ONU serial number.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   onu_sn_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_onu_sn_set(bdmf_object_handle mo_, const rdpa_onu_sn_t * onu_sn_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_onu_sn, onu_sn_, sizeof(*onu_sn_));
}


/** Get gpon/password attribute.
 *
 * Get ONU password.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  password_ Attribute value
 * \param[in]   size_ buffer size
 * \return number of bytes read >=0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_password_get(bdmf_object_handle mo_, void * password_, uint32_t size_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_password, password_, size_);
}


/** Set gpon/password attribute.
 *
 * Set ONU password.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   password_ Attribute value
 * \param[in]   size_ buffer size
 * \return number of bytes written >=0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_password_set(bdmf_object_handle mo_, const void * password_, uint32_t size_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_password, password_, size_);
}


/** Get gpon/user_ic attribute.
 *
 * Get User indication callback.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  user_ic_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_user_ic_get(bdmf_object_handle mo_, void * *user_ic_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_user_ic, &_nn_);
    *user_ic_ = (void *)(long)_nn_;
    return _rc_;
}


/** Set gpon/user_ic attribute.
 *
 * Set User indication callback.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   user_ic_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_user_ic_set(bdmf_object_handle mo_, void * user_ic_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_gpon_attr_user_ic, (long)user_ic_);
}


/** Get gpon/link_stat attribute.
 *
 * Get Link statistics.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  link_stat_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_link_stat_get(bdmf_object_handle mo_, rdpa_gpon_stat_t * link_stat_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_link_stat, link_stat_, sizeof(*link_stat_));
}


/** Get gpon/overhead_cfg attribute.
 *
 * Get Overhead configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  overhead_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_overhead_cfg_get(bdmf_object_handle mo_, rdpa_gpon_overhead_cfg_t * overhead_cfg_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_overhead_cfg, overhead_cfg_, sizeof(*overhead_cfg_));
}


/** Get gpon/transceiver_power_level attribute.
 *
 * Get Transceiver power level configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  transceiver_power_level_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_transceiver_power_level_get(bdmf_object_handle mo_, bdmf_number *transceiver_power_level_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_transceiver_power_level, &_nn_);
    *transceiver_power_level_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Get gpon/equalization_delay attribute.
 *
 * Get Equalization delay.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  equalization_delay_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_equalization_delay_get(bdmf_object_handle mo_, bdmf_number *equalization_delay_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_equalization_delay, &_nn_);
    *equalization_delay_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Get gpon/encryption_key attribute.
 *
 * Get Encryption key.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  encryption_key_ Attribute value
 * \param[in]   size_ buffer size
 * \return number of bytes read >=0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_encryption_key_get(bdmf_object_handle mo_, void * encryption_key_, uint32_t size_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_encryption_key, encryption_key_, size_);
}


/** Get gpon/tcont_counter_assigment attribute.
 *
 * Get TCONT counter assigment.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  tcont_counter_assigment_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_counter_assigment_get(bdmf_object_handle mo_, bdmf_number *tcont_counter_assigment_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_tcont_counter_assigment, &_nn_);
    *tcont_counter_assigment_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Set gpon/tcont_counter_assigment attribute.
 *
 * Set TCONT counter assigment.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   tcont_counter_assigment_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_counter_assigment_set(bdmf_object_handle mo_, bdmf_number tcont_counter_assigment_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_gpon_attr_tcont_counter_assigment, tcont_counter_assigment_);
}


/** Get gpon/ds_fec_state attribute.
 *
 * Get DS FEC enable state.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  ds_fec_state_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_ds_fec_state_get(bdmf_object_handle mo_, bdmf_boolean *ds_fec_state_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_ds_fec_state, &_nn_);
    *ds_fec_state_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Get gpon/fec_stat attribute.
 *
 * Get FEC statistics.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  fec_stat_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_fec_stat_get(bdmf_object_handle mo_, rdpa_fec_stat_t * fec_stat_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_fec_stat, fec_stat_, sizeof(*fec_stat_));
}


/** Set gpon/send_ploam attribute.
 *
 * Set Send ploam.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   send_ploam_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_gpon_send_ploam_set(bdmf_object_handle mo_, const rdpa_send_ploam_params_t * send_ploam_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_send_ploam, send_ploam_, sizeof(*send_ploam_));
}


/** Get gpon/dba_interval attribute.
 *
 * Get DBA Status Report.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  dba_interval_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_dba_interval_get(bdmf_object_handle mo_, rdpa_dba_interval_t *dba_interval_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_dba_interval, &_nn_);
    *dba_interval_ = (rdpa_dba_interval_t)_nn_;
    return _rc_;
}


/** Set gpon/dba_interval attribute.
 *
 * Set DBA Status Report.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   dba_interval_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_dba_interval_set(bdmf_object_handle mo_, rdpa_dba_interval_t dba_interval_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_gpon_attr_dba_interval, dba_interval_);
}


/** Get gpon/prbs attribute.
 *
 * Get PRBS.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  prbs_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_prbs_get(bdmf_object_handle mo_, rdpa_prbs_t * prbs_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_prbs, prbs_, sizeof(*prbs_));
}


/** Set gpon/prbs attribute.
 *
 * Set PRBS.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   prbs_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_prbs_set(bdmf_object_handle mo_, const rdpa_prbs_t * prbs_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_prbs, prbs_, sizeof(*prbs_));
}


/** Get gpon/rogue_onu attribute.
 *
 * Get rogue onu.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  rogue_onu_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_rogue_onu_get(bdmf_object_handle mo_, rdpa_rogue_onu_t * rogue_onu_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_gpon_attr_rogue_onu, rogue_onu_, sizeof(*rogue_onu_));
}


/** Set gpon/rogue_onu attribute.
 *
 * Set rogue onu.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   rogue_onu_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_rogue_onu_set(bdmf_object_handle mo_, const rdpa_rogue_onu_t * rogue_onu_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_gpon_attr_rogue_onu, rogue_onu_, sizeof(*rogue_onu_));
}


/** Get gpon/gem_block_size attribute.
 *
 * Get Gem block size.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[out]  gem_block_size_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_block_size_get(bdmf_object_handle mo_, bdmf_number *gem_block_size_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_gpon_attr_gem_block_size, &_nn_);
    *gem_block_size_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Set gpon/gem_block_size attribute.
 *
 * Set Gem block size.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   gem_block_size_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_block_size_set(bdmf_object_handle mo_, bdmf_number gem_block_size_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_gpon_attr_gem_block_size, gem_block_size_);
}


/** Get gpon/gem_enable attribute entry.
 *
 * Get Enable GEM.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  gem_enable_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_enable_get(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean *gem_enable_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_gpon_attr_gem_enable, (bdmf_index)ai_, &_nn_);
    *gem_enable_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Set gpon/gem_enable attribute entry.
 *
 * Set Enable GEM.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   gem_enable_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_enable_set(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean gem_enable_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_gpon_attr_gem_enable, (bdmf_index)ai_, gem_enable_);
}


/** Get next gpon/gem_enable attribute entry.
 *
 * Get next Enable GEM.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_enable_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_gem_enable, (bdmf_index *)ai_);
}


/** Get gpon/gem_ds_cfg attribute entry.
 *
 * Get Downstream GEM configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  gem_ds_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_ds_cfg_get(bdmf_object_handle mo_, bdmf_object_handle ai_, rdpa_gpon_gem_ds_cfg_t * gem_ds_cfg_)
{
    return bdmf_attrelem_get_as_buf(mo_, rdpa_gpon_attr_gem_ds_cfg, (bdmf_index)ai_, gem_ds_cfg_, sizeof(*gem_ds_cfg_));
}


/** Set gpon/gem_ds_cfg attribute entry.
 *
 * Set Downstream GEM configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   gem_ds_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_ds_cfg_set(bdmf_object_handle mo_, bdmf_object_handle ai_, const rdpa_gpon_gem_ds_cfg_t * gem_ds_cfg_)
{
    return bdmf_attrelem_set_as_buf(mo_, rdpa_gpon_attr_gem_ds_cfg, (bdmf_index)ai_, gem_ds_cfg_, sizeof(*gem_ds_cfg_));
}


/** Get next gpon/gem_ds_cfg attribute entry.
 *
 * Get next Downstream GEM configuration.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_ds_cfg_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_gem_ds_cfg, (bdmf_index *)ai_);
}


/** Get gpon/gem_encryption attribute entry.
 *
 * Get Downstream GEM flow Encryption mode.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  gem_encryption_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_encryption_get(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean *gem_encryption_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_gpon_attr_gem_encryption, (bdmf_index)ai_, &_nn_);
    *gem_encryption_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Set gpon/gem_encryption attribute entry.
 *
 * Set Downstream GEM flow Encryption mode.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   gem_encryption_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_encryption_set(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean gem_encryption_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_gpon_attr_gem_encryption, (bdmf_index)ai_, gem_encryption_);
}


/** Get next gpon/gem_encryption attribute entry.
 *
 * Get next Downstream GEM flow Encryption mode.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_gem_encryption_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_gem_encryption, (bdmf_index *)ai_);
}


/** Get gpon/tcont_alloc_id attribute entry.
 *
 * Get TCONT Alloc ID.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  tcont_alloc_id_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_alloc_id_get(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_number *tcont_alloc_id_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_gpon_attr_tcont_alloc_id, (bdmf_index)ai_, &_nn_);
    *tcont_alloc_id_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Set gpon/tcont_alloc_id attribute entry.
 *
 * Set TCONT Alloc ID.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   tcont_alloc_id_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_alloc_id_set(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_number tcont_alloc_id_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_gpon_attr_tcont_alloc_id, (bdmf_index)ai_, tcont_alloc_id_);
}


/** Delete gpon/tcont_alloc_id attribute entry.
 *
 * Delete TCONT Alloc ID.
 * \param[in]   mo_ gpon object handle
 * \param[in]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_alloc_id_delete(bdmf_object_handle mo_, bdmf_object_handle ai_)
{
    return bdmf_attrelem_delete(mo_, rdpa_gpon_attr_tcont_alloc_id, (bdmf_index)ai_);
}


/** Get next gpon/tcont_alloc_id attribute entry.
 *
 * Get next TCONT Alloc ID.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_alloc_id_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_tcont_alloc_id, (bdmf_index *)ai_);
}


/** Get gpon/tcont_assign_ploam_flag attribute entry.
 *
 * Get TCONT Assign alloc id message arrived.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  tcont_assign_ploam_flag_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_assign_ploam_flag_get(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean *tcont_assign_ploam_flag_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_gpon_attr_tcont_assign_ploam_flag, (bdmf_index)ai_, &_nn_);
    *tcont_assign_ploam_flag_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Get next gpon/tcont_assign_ploam_flag attribute entry.
 *
 * Get next TCONT Assign alloc id message arrived.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_assign_ploam_flag_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_tcont_assign_ploam_flag, (bdmf_index *)ai_);
}


/** Get gpon/tcont_stat attribute entry.
 *
 * Get TCONT statistics.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  tcont_stat_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_stat_get(bdmf_object_handle mo_, bdmf_object_handle ai_, rdpa_tcont_stat_t * tcont_stat_)
{
    return bdmf_attrelem_get_as_buf(mo_, rdpa_gpon_attr_tcont_stat, (bdmf_index)ai_, tcont_stat_, sizeof(*tcont_stat_));
}


/** Get next gpon/tcont_stat attribute entry.
 *
 * Get next TCONT statistics.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_stat_get_next(bdmf_object_handle mo_, bdmf_object_handle * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_gpon_attr_tcont_stat, (bdmf_index *)ai_);
}


/** Set gpon/tcont_flush attribute entry.
 *
 * Set Flush TCONT Front End Buffer and BBH Queue.
 * \param[in]   mo_ gpon object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   tcont_flush_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_gpon_tcont_flush_set(bdmf_object_handle mo_, bdmf_object_handle ai_, bdmf_boolean tcont_flush_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_gpon_attr_tcont_flush, (bdmf_index)ai_, tcont_flush_);
}

/** @} end of gpon Doxygen group */




#endif /* _RDPA_AG_GPON_H_ */
