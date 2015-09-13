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
      '@type'        => array(
        'value' => 'dcat:Dataset',
        'type'  => 'string',
      ),
      'frequency'    => array(
        'value' => '[node:field-frequency]',
        'type'  => 'string',
      ),
      'contactPoint' => array(
        '@type'    => array(
          'value' => 'v:VCard',
          'type'  => '',
        ),
        'fn'       => array(
          'value' => '[node:field_contact_name]',
          'type'  => '',
        ),
        'hasEmail' => array(
          'value' => '[node:field-contact-email]',
          'type'  => '',
        ),
      ),
      'conformsTo'   => array(
        'value' => '',
        'type'  => 'string',
      ),
      'description'  => array(
        'value' => '[node:body]',
        'type'  => 'string'
      ),
      'distribution' => array(
        'odsm_entity_reference' => array(
          'value' => 'field_resources',
          'type'  => '',
        ),
        '@type'                 => array(
          'value' => 'dcat:Distribution',
          'type'  => '',
        ),
        'accessURL'             => array(
          'value' => '[node:field-resources:Nth:url]',
          'type'  => ''
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
          'type'  => 'string',
        ),
        'description'           => array(
          'value' => '[node:field-resources:Nth:body]',
          'type'  => 'string',
        ),
        'title'                 => array(
          'value' => '[node:field-resources:Nth:title]',
          'type'  => 'string',
        ),
      ),
      'identifier'   => array(
        'value' => '[node:uuid]',
        'type'  => 'string',
      ),
      'issued'       => array(
        'value' => '',
        'type'  => 'string',
      ),
      'keyword'      => array(
        'value' => '[node:field-tags]',
        'type'  => 'array',
      ),
      'landingPage'  => array(
        'value' => '[node:url]',
        'type'  => '',
      ),
      'language'     => array(
        'value' => 'http://publications.europa.eu/resource/authority/language/ITA',
        'type'  => '',
      ),
      'modified'     => array(
        'value' => '[node:changed:custom:Y-m-d]',
        'type'  => 'string',
      ),
      'publisher'    => array(
        '@type' => array(
          'value' => 'foaf:Agent',
          'type'  => '',
        ),
        'name'  => array(
          'value' => '[node:field-organization-ref:title]',
          'type'  => 'string',
        ),
        'publisherType'  => array(
          'value' => '[node:field-organization-ref:field_publisher_type]',
          'type'  => 'string',
        )
      ),
      'spatial'      => array(
        'value' => '[node:field_spatial]',
        'type'  => 'string',
      ),
      'temporal'     => array(
        'value' => '[node:field_temporal_coverage]',
        'type'  => 'string',
      ),
      'theme'        => array(
        'value' => '',
        'type'  => 'array',
      ),
      'title'        => array(
        'value' => '[node:title]',
        'type'  => 'string',
      )
    ),
    'endpoint'     => 'dcat.json',
    'arguments'    => array()
  );

  return $open_data_schema_apis;
}