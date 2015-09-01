<?php

function open_data_dcat_ap_catalog(&$result) {

  $result['@context'] = 'https://project-open-data.cio.gov/v1.1/schema/catalog.jsonld';
  $result['@id'] = url('data.json', array('absolute' => TRUE));
  $result['@type'] = 'dcat:Catalog';
  $result['conformsTo'] = 'https://project-open-data.cio.gov/v1.1/schema';
  $result['describedBy'] = 'https://project-open-data.cio.gov/v1.1/schema/catalog.json';

}