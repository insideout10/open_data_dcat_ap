<?php

/**
 * Implements hook_open_data_schema_apis_defaults().
 */
function open_data_dcat_ap_open_data_schema_apis_defaults() {
  $open_data_schema_apis = array();

  $open_data_schema_apis['dcat_ap_json_1_01'] = array(
    'name'         => 'DCAT-AP Json 1.01',
    'enabled'      => 1,
    'machine_name' => 'dcat_ap_json_1_01',
    'api_schema'   => 'dcat_ap_1_01',
    'description'  => NULL,
    'type'         => 'node',
    'bundle'       => 'dataset',
    'mapping'      => array(
      '@type'                  => array(
        'value' => 'dcat:Dataset',
        'type'  => 'string',
      ),
//      'accessLevel'            => array(
//        'value' => '[node:field-public-access-level]',
//        'type'  => 'string',
//      ),
//      'rights'                 => array(
//        'value' => '',
//        'type'  => 'string',
//      ),
      'accrualPeriodicity'     => array(
        'value' => '[node:field-frequency]',
        'type'  => 'string',
      ),
//      'bureauCode'             => array(
//        'value' => '018:10',
//        'type'  => 'array',
//      ),
      'contactPoint'           => array(
        '@type'    => array(
          'value' => '',
          'type'  => '',
        ),
        'fn'       => array(
          'value' => '[node:field_contact_name] || [node:author:name]',
          'type'  => '',
        ),
        'hasEmail' => array(
          'value' => 'mailto:[node:field-contact-email]',
          'type'  => '',
        ),
      ),
//      'describedBy'            => array(
//        'value' => '[node:field-data-dictionary]',
//        'type'  => 'string',
//      ),
//      'describedByType'        => array(
//        'value' => '',
//        'type'  => 'string',
//      ),
      'conformsTo'             => array(
        'value' => '',
        'type'  => 'string',
      ),
//      'dataQuality'            => array(
//        'value' => '',
//        'type'  => 'boolean',
//      ),
      'description'            => array(
        'value' => '[node:body]',
        'type'  => 'string',
      ),
      'distribution'           => array(
        'odsm_entity_reference' => array(
          'value' => 'field_resources',
          'type'  => '',
        ),
        '@type'                 => array(
          'value' => 'dcat:Distribution',
          'type'  => '',
        ),
        'downloadURL'           => array(
          'value' => '[node:field-resources:Nth:field-link-api:url] || [node:field-resources:Nth:field_link_remote_file] || [node:field-resources:Nth:field-upload:url]',
          'type'  => '',
        ),
        'mediaType'             => array(
          'value' => '[node:field-resources:Nth:field-upload:mime]',
          'type'  => '',
        ),
        'format'                => array(
          'value' => '[node:field-resources:Nth:field-format:name]',
          'type'  => '',
        ),
        'accessURL'             => array(
          'value' => '',
          'type'  => '',
        ),
        'description'           => array(
          'value' => '',
          'type'  => '',
        ),
        'title'                 => array(
          'value' => '',
          'type'  => '',
        ),
//        'conformsTo'            => array(
//          'value' => '',
//          'type'  => '',
//        ),
//        'describedBy'           => array(
//          'value' => '',
//          'type'  => '',
//        ),
//        'describedByType'       => array(
//          'value' => '',
//          'type'  => '',
//        ),
      ),
      'identifier'             => array(
        'value' => '[node:uuid]',
        'type'  => 'string',
      ),
      'issued'                 => array(
        'value' => '',
        'type'  => 'string',
      ),
      'keyword'                => array(
        'value' => '[node:field-tags]',
        'type'  => 'array',
      ),
      'landingPage'            => array(
        'value' => '',
        'type'  => 'string',
      ),
      'language'               => array(
        'value' => 'en',
        'type'  => 'array',
      ),
//      'license'                => array(
//        'value' => '[node:field_license]',
//        'type'  => 'string',
//      ),
      'modified'               => array(
        'value' => '[node:changed:custom:Y-m-d]',
        'type'  => 'string',
      ),
//      'primaryITInvestmentUII' => array(
//        'value' => '',
//        'type'  => 'string',
//      ),
//      'programCode'            => array(
//        'value' => '018:001',
//        'type'  => 'array',
//      ),
      'publisher'              => array(
        '@type'             => array(
          'value' => 'org:Organization',
          'type'  => '',
        ),
        'name'              => array(
          'value' => '[node:og_group_ref]',
          'type'  => '',
        ),
//        'subOrganizationOf' => array(
//          'value' => '',
//          'type'  => '',
//        ),
      ),
//      'references'             => array(
//        'value' => '[node:field_related_content]',
//        'type'  => 'array',
//      ),
      'spatial'                => array(
        'value' => '[node:field_spatial]',
        'type'  => 'string',
      ),
//      'systemOfRecords'        => array(
//        'value' => '',
//        'type'  => 'string',
//      ),
      'temporal'               => array(
        'value' => '[node:field_temporal_coverage]',
        'type'  => 'string',
      ),
//      'isPartOf'               => array(
//        'value' => '',
//        'type'  => 'string',
//      ),
      'theme'                  => array(
        'value' => '',
        'type'  => 'array',
      ),
      'title'                  => array(
        'value' => '[node:title]',
        'type'  => 'string',
      ),
    ),
    'endpoint'     => 'dcat.json',
    'arguments'    => array(),
  );

  return $open_data_schema_apis;
}