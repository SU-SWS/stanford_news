<?php
/**
 * @file
 * stanford_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descriptor_info|node|stanford_news_item|default';
  $field_group->group_name = 'group_descriptor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => '',
    'weight' => '11',
    'children' => array(
      0 => 'field_s_news_date',
      1 => 'field_s_news_source',
      2 => 'group_s_news_postedin',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_descriptor_info|node|stanford_news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_advanced|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '10',
    'children' => array(
      0 => 'field_s_news_featured',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_news_advanced|node|stanford_news_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_categories_style|node|stanford_news_item|taxonomy';
  $field_group->group_name = 'group_s_news_categories_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Categories Style',
    'weight' => '18',
    'children' => array(
      0 => 'field_s_news_categories',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categories Style',
      'instance_settings' => array(
        'classes' => 'descriptor descriptor-btn',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_news_categories_style|node|stanford_news_item|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_categories|node|stanford_news_item|default';
  $field_group->group_name = 'group_s_news_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories Div',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_s_news_categories|node|stanford_news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_external_info|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_external_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add/Edit External Article Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_news_date',
      1 => 'field_s_news_source',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add/Edit External Article Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_news_external_info|node|stanford_news_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_news_item|taxonomy';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '18',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_col1|node|stanford_news_item|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_news_item|taxonomy';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '19',
    'children' => array(
      0 => 'body',
      1 => 'title',
      2 => 'group_s_postcard_date_style',
      3 => 'group_s_news_categories_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_col2|node|stanford_news_item|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_news_item|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '11',
    'children' => array(
      0 => 'body',
      1 => 'field_s_news_attachment',
      2 => 'field_s_news_link',
      3 => 'group_descriptor_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|node|stanford_news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_date_style|node|stanford_news_item|taxonomy';
  $field_group->group_name = 'group_s_postcard_date_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Date Style',
    'weight' => '15',
    'children' => array(
      0 => 'field_s_news_date',
      1 => 'field_s_news_source',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date Style',
      'instance_settings' => array(
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_date_style|node|stanford_news_item|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|node|stanford_news_item|default';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '10',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|node|stanford_news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_news_item|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_content',
      1 => 'group_s_postcard_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|node|stanford_news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_news_item|taxonomy';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_postcard_col1',
      1 => 'group_s_postcard_col2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|node|stanford_news_item|taxonomy'] = $field_group;

  return $export;
}
