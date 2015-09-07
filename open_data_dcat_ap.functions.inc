<?php

/**
 * Alter a dataset entry.
 * @since 1.0.0
 *
 * @param $dataset
 */
function open_data_dcat_ap_dataset_alter(&$dataset) {

  // *description* is mandatory.
  if (!isset($dataset['description'])) {
    $dataset['description'] = '';
  }

  // *contactPoint* is recommended, remove it if we have 'Anonimo'.
  if (isset($dataset['contactPoint']) && isset($dataset['contactPoint']['fn']) && ('Anonimo' === $dataset['contactPoint']['fn'])) {
    unset($dataset['contactPoint']);
  }

  // Remove trailing spaces in the description.
  $dataset['description'] = strip_tags($dataset['description']);

  // Language is always IT
  $dataset['language'] = 'http://publications.europa.eu/resource/authority/language/ITA';

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
}
