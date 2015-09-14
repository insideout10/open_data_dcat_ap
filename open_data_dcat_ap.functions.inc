<?php

/**
 * Alter a dataset entry.
 * @since 1.0.0
 *
 * @param $dataset
 */
function open_data_dcat_ap_dataset_alter(&$dataset) {

  $publisher_types = array(
    'http://purl.org/adms/publishertype/Academia-ScientificOrganisation',
    'http://purl.org/adms/publishertype/Company',
    'http://purl.org/adms/publishertype/IndustryConsortium',
    'http://purl.org/adms/publishertype/LocalAuthority',
    'http://purl.org/adms/publishertype/NationalAuthority',
    'http://purl.org/adms/publishertype/NonGovernmentalOrganisation',
    'http://purl.org/adms/publishertype/NonProfitOrganisation',
    'http://purl.org/adms/publishertype/PrivateIndividual(s)',
    'http://purl.org/adms/publishertype/RegionalAuthority',
    'http://purl.org/adms/publishertype/StandardisationBody',
    'http://purl.org/adms/publishertype/SupraNationalAuthority'
  );

  // *description* is mandatory.
  if (!isset($dataset['description'])) {
    $dataset['description'] = '';
  }

  // *contactPoint* is recommended, remove it if we have 'Anonimo'.
  if (isset($dataset['contactPoint']) && isset($dataset['contactPoint']['fn']) && ('Anonimo' === $dataset['contactPoint']['fn'])) {
    unset($dataset['contactPoint']);
  }

  // Check the publisher properties.
  if (isset($dataset['publisher'])) {

    // *name* is mandatory, set _(unknown)_ if emtpy.
    if (empty($dataset['publisher']['name'])) {
      $dataset['publisher']['name'] = '(senza nome)';
    }

    // *publisherType* is recommended and uses the ADMS publisher type vocabulary.
    if (isset($dataset['publisher']['publisherType']) && is_numeric($dataset['publisher']['publisherType'])) {

      $publisher_type_index = (int) $dataset['publisher']['publisherType'];
      if (0 < $publisher_type_index && sizeof($publisher_types) >= $publisher_type_index) {
        $dataset['publisher']['publisherType'] = $publisher_types[$publisher_type_index - 1];
      }
    }

  }

  // Remove trailing spaces in the description.
  $dataset['description'] = strip_tags($dataset['description']);

  // *description* is required, therefore we provide a placeholder if empty.
  if (empty($dataset['description'])) {
    $dataset['description'] = '(senza descrizione)';
  }

  // Set the mediaType for the distribution.
  if (isset($dataset['distribution'])) {
    foreach ($dataset['distribution'] as $num => $dist) {
      if (isset($dist['description'])) {
        $dist['description'] = strip_tags($dist['description']);
      }
      if (isset($dist['title'])) {
        $dist['title'] = strip_tags($dist['title']);
      }
      if ($dist['format'] && !$dist['mediaType']) {
        include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';
        $map                                        = file_mimetype_mapping();
        $dataset['distribution'][$num]['mediaType'] = isset($map['mimetypes'][$map['extensions'][$dist['format']]]) ? $map['mimetypes'][$map['extensions'][$dist['format']]] : 'text/html';
      }
      if ($dist['downloadURL'] && !$dist['mediaType']) {
        if ($dist['format']) {
          $media_type        = recline_get_data_type($dist['format']);
          $dist['mediaType'] = $media_type ? $media_type : t('unknown');
        }
        else {
          $dist['mediaType'] = t('unknown');
        }
      }
      // Remove empty items.
      foreach ($dist as $i => $v) {
        if (!$v) {
          unset($dataset['distribution'][$num][$i]);
        }
      }
    }
  }

  // Our *spatial* is not compatible with DCAT-AP 1.01
  if (isset($dataset['spatial'])) {
    unset($dataset['spatial']);
  }

}
